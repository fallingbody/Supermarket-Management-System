// IMPORTING LIBRARIES //
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

// ANSI colour coding and text styles //
// ADDING OF COLOUR FOR OUTPUT TEXT TEXT //
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define BOLD "\x1b[1m"
#define ITALIC "\x1b[3m"

// DISPLAY PRODUCTS //
void displayProducts()
{
    // SHOWING PRODUCTS USING FILE IN TABULAR FORM //
    printf(YELLOW "\t\t\t\t\\OUR STOCK\\\n");
    // MAKING STRING FOR DISPLAYING //
    char data[50];
    // OPENING PRODUCT FILE //
    FILE *displayfile = fopen("products.txt", "r");
    // PRINTING PRODUCTS IN TABULAR FORM //
    printf("\t\tS NO.\t||\tNAME\t\t|\tPRICE\t|\tQUANTITY\n" RESET);
    // FETCHING DATA LINE BY LINE //
    for (int i = 1; fgets(data, sizeof(data), displayfile) != NULL; i++)
    {
        // MAKING VARIABLES TO STORE DATA //
        char productName[20];
        int price, quantity;
        // FETCHING DATA FROM FILE //
        sscanf(data, "%s %d %d", &productName, &price, &quantity);
        // PRINTING PRODUCTS IN TABULAR FORM //
        printf("\t\t%d.\t||\t%s\t\t|\t$%d\t|\t%d\n", i, productName, price, quantity);
    }
}
// PRODUCTS ARE DISPLAYED FROM THE FILE //

// ADD PRODUCT //
void addProduct()
{
    // MAKING VARIABLE FOR INPUTING NEW PRODUCT DATA //
    char name[20];
    int price, quantity;
    // INPUTING //
    printf("\t\t\t\t>>ENTER PRODUCT NAME :- ");
    scanf("%s", &name);
    printf("\t\t\t\t>>ENTER PRODUCT PRICE :- ");
    scanf("%d", &price);
    printf("\t\t\t\t>>ENTER PRODUCT QUANTITY :- ");
    scanf("%d", &quantity);
    printf("\t\t\t\t>>YES!! ADMIN YOUR PRODUCT IS ADDED IN STOCK.\n\n");
    // OPENING FILE AND ADDING NEW PRODUCT DATA IN FILE //
    FILE *fptr = fopen("products.txt", "a");
    fprintf(fptr, "%s %d %d\n", name, price, quantity);
    fclose(fptr);
}
// PRODUCT IS ADDED IN FILE //

// DELETE ANY ONE PRODUCT //
void deleteProduct()
{
    printf("\t\t\t\t>>>ENTER PRODUCT NAME TO DELETE :- ");
    // TAKING INPUT OF PRODUCT WHICH ADMIN WANTS TO DELETE //
    char delete_product[20];
    scanf("%s", delete_product);
    // OPENING PRODUCTS FILE //
    FILE *products = fopen("products.txt", "r");
    // OPENING TEMP FILE WHERE THE PRODUCT FILE DATA IS COPIED EXCEPT DELETED PRODUCT DATA //
    FILE *temp = fopen("temp.txt", "w");
    char data[50];
    while (fgets(data, sizeof(data), products) != NULL)
    {
        if (strstr(data, delete_product) == NULL)
            fputs(data, temp);
    }
    fclose(temp);
    fclose(products);

    // DELETING INITIAL PRODUCT DATA //
    remove("products.txt");

    // TRANSFORMING TEMP FILE INTO MAIN FILE BY TRANSFERING DATA //
    rename("temp.txt", "products.txt");

    printf("\t\t>>YES!! ADMIN YOUR PRODUCT IS DELETED SUCCESSFULLY.\n\n");
}
// PRODUCT IS DELETED FROM OUR STOCK //

// ADMIN'S FUNCTION //
void admin()
{
    // POPUP FOR ADMIN //
    printf("\t\t\t\t>>HELLO ADMIN!! WELCOME BACK HOW CAN I HELP YOU??\n");
    int adminChoice;
    do
    {
        // PRESSING DETAILS FOR ADMIN //
        printf("\t\t\t\t>>PRESS 0 FOR EXIT.\n");
        printf("\t\t\t\t>>PRESS 1 FOR DISPLAY ITEMS.\n");
        printf("\t\t\t\t>>PRESS 2 FOR ADD ITEMS.\n");
        printf("\t\t\t\t>>PRESS 3 FOR DELETING ITEM.\n");
        printf("\t\t\t\t>>PRESS NUMBER :- ");
        // MAKING VARIABLE FOR TAKING INPUT FROM ADMIN TO PERFORM OPERATION //
        scanf("%d", &adminChoice);
        // USING SWITCH CASE METHOD FOR DISPLAY, ADD AND DELETE PRODUCTS //
        switch (adminChoice)
        {
            // DISPLAYING STOCK //
        case 1:
            displayProducts();
            break;
            // ADDING PRODUCT //
        case 2:
            addProduct();
            break;
            // DELETING PRODUCT //
        case 3:
            deleteProduct();
            break;
            // EXITING //
        case 0:
            printf(CYAN ITALIC "Exiting admin panel........\n" RESET);
            exit(0);
            break;
            // INVALID FOR DIFF VALUES //
        default:
            printf(RED "Invalid choice. Please enter a valid option.\n" RESET);
        }
    } while (adminChoice != 0);
}
// ADMIN FUNCTION IS FINISHED WHERE ADMIN CAN DISPLAY, ADD AND DELETE ITEMS //

// BOOLEAN FUNCTION TO CHECK USERNAME EXISTS OR NOT //
// IF BOOLEAN FUNCTION GIVES TRUE THEN IF CONDITION WILL WORK //
bool userAvailable(char username[], char pass[])
{
    // OPENING CUSTOMER'S FILE //
    FILE *userinfo = fopen("customers.txt", "r");
    char userdata[50];
    char userPass[20];
    // READING EACH LINE OF DATA TILL END OF FILE //
    while (fgets(userdata, sizeof(userdata), userinfo) != NULL)
    {
        // USERNAME EXISTS //
        if (strstr(userdata, username) != NULL)
        {
            // STORES USER DATA IN VARIABLES //
            sscanf(userdata, "%s %s", &username, &userPass);

            // ENTERED PASS IS NOT CORRECT //
            if (strcmp(pass, userPass) != 0)
            {
                printf("\t\t\t\t>>WRONG PASSWORD\n");
                printf("\t\t\t\t>>TRY AGAIN");
                fclose(userinfo); // CLOSE FILE //
                exit(0);
            }
            // IF IF CONDITIONS NOT WORKED THEN CLOSE FILE AND GIVE TRUE //
            fclose(userinfo);
            return true;
        }
    }
    // IF USER IS NOT FOUND //
    // IF ALL CONDITIONS NOT WORKED THEN CLOSE FILE AND GIVE FALSE //
    fclose(userinfo);
    return false;
}
// BOOLEAN FUNCTION THE END //

// DISPLAY PRODUCTS //
void displaycart()
{
    // SHOWING PRODUCTS USING FILE IN TABULAR FORM //
    printf(YELLOW "\t\t\t\t\\OUR STOCK\\\n");
    // MAKING STRING FOR DISPLAYING //
    char data[50];
    FILE *displayfile = fopen("cartlist.txt", "r");
    printf("\t\tS NO.\t||\tNAME\t\t|\tQUANTITY\n" RESET);
    for (int i = 1; fgets(data, sizeof(data), displayfile) != NULL; i++)
    {
        char productName[20];
        int quantity;
        sscanf(data, "%s %d %d", &productName, &quantity);
        printf("\t\t%d.\t||\t%s\t\t|\t%d\n", i, productName, quantity);
    }
}
// PRODUCTS ARE DISPLAYED FROM THE FILE //

// ADD PRODUCT //
void addcart()
{

    char name[20];
    int price, quantity;
    printf("\t\t\t\t>>ENTER PRODUCT NAME :- ");
    scanf("%s", &name);
    printf("\t\t\t\t>>ENTER PRODUCT QUANTITY :- ");
    scanf("%d", &quantity);
    printf("\t\t\t\t>>YES!! YOUR PRODUCT IS ADDED IN CART.\n\n");
    FILE *fptr = fopen("cartlist.txt", "a");
    fprintf(fptr, "%s %d\n", name, quantity);
    fclose(fptr);
}
// PRODUCT IS ADDED IN FILE //

void bill()
{
    float netPrice = 0, totalPrice = 0;
    char c[200];
    FILE *f = fopen("cartlist.txt", "r");
    FILE *a = fopen("products.txt", "r");
    printf("\t\tS NO.\t||\tNAME\t\t|\tPRICE\t|\tQUANTITY\n");
    for (int i = 1; fgets(c, sizeof(c), f) != NULL; i++)
    {
        char p[20];
        int quantity;
        sscanf(c, "%s %d", &p, &quantity);
        char nc[200];
        while (fgets(nc, sizeof(nc), a) != NULL)
        {
            char nm[20];
            int qn, pr;
            sscanf(nc, "%s %d %d", nm, &pr, &qn);
            if (strcmp(nm, p) == 0)
            {
                totalPrice = pr * quantity;
                netPrice += totalPrice;
                printf("\t\t%d.\t||\t%s\t\t|\t%d\t|\t%f\n", i, nm, quantity, totalPrice);
            }
        }

        rewind(a);
        // we get the price from this code //
    }
    printf("\t\t\t\t NET PRICE :- $%.2f\n", netPrice);
    printf("\t\t\t\t INCLUDING 18%c GST :- $%.2f\n", '%', netPrice * 0.18);
    printf("\t\t\t\t GRAND PRICE :- $%.2f\n", (netPrice + (netPrice * 0.18)));
    fclose(f);
    fclose(a);
}

// CUSTOMER'S FUNCTION WITH TWO INFO USERNAME AND PASSWORD //
void customer(char name[], char pass[])
{
    // USING BOOLEAN FUNCTION IN IF CONDITION IF TRUE IF CONDITION WORKS AND FALSE ELSE CONDITION WORK //

    // TRUE //
    if (userAvailable(name, pass))
    {
        // TRUE MEANS OLD CUSTOMER //
        printf("\t\t\t\t>>WELCOME BACK OUR OLD USER GLAD TO SEE YOU AGAIN!!\n");
    }

    // FLASE //
    else
    {
        // FALSE MEANS NEW CUSTOMER THEN SAVING THE DATA OF CUSTOMER IN CUSTOMER'S FILE //
        printf("\t\t\t\t>>Oooo YOU SEEMED TO BE A NEW USER.\n");
        // ADDING USER INFO IN CUSTOMER'S FILE //
        FILE *fptr = fopen("customers.txt", "a");
        fprintf(fptr, "%s %s\n", name, pass);
        fclose(fptr);
        printf("\t\t\t\t>>WELCOME!! YOU ARE ADDED IN OUR SYSTEM AS A CUSTOMER\n");
        // ADDED //
    }
    int customerChoice;
    do
    {
        // PRESSING DETAILS FOR ADMIN //
        printf("\t\t\t\t>>PRESS 0 FOR EXIT.\n");
        printf("\t\t\t\t>>PRESS 1 FOR DISPLAY STOCK.\n");
        printf("\t\t\t\t>>PRESS 2 FOR ADD CART.\n");
        printf("\t\t\t\t>>PRESS 3 FOR DISPLAY CART.\n");
        printf("\t\t\t\t>>PRESS 4 FOR BILL.\n");
        printf("\t\t\t\t>>PRESS NUMBER :- ");
        // MAKING VARIABLE FOR TAKING INPUT FROM ADMIN TO PERFORM OPERATION //
        scanf("%d", &customerChoice);
        // USING SWITCH CASE METHOD FOR DISPLAY, ADD AND DELETE PRODUCTS //
        switch (customerChoice)
        {
            // DISPLAYING STOCK //
        case 1:
            displayProducts();
            break;
            // ADDING PRODUCT //
        case 2:
            addcart();
            break;
            // DELETING PRODUCT //
        case 3:
            displaycart();
            break;
        case 4:
            bill();
            break;

        case 0:
            printf(CYAN ITALIC "Exiting admin panel........\n" RESET);
            exit(0);
            break;
            // INVALID FOR DIFF VALUES //
        default:
            printf(RED "Invalid choice. Please enter a valid option.\n" RESET);
        }
    } while (customerChoice != 0);
}


// MAIN FUNCTION //
int main()
{
    remove("cartlist.txt");
    // INTERFACE AND SOME LOOKS //
    printf(".............................................HELLO WELCOME TO OUR SITE.........................................................\n");
    printf("       .........................................WE NEED SOME DETAILS..................................\n");

    // ADMIN DETAILS //
    char adminusername1[30] = "Ashirwad", adminpass1[20] = "Bhawna";
    // MAKING TWO STRINGS TO STORE DATA ENTERED BY USERNAME AND PASSWORD //
    char username[30], pass[20];
    printf("\t\t\t\t\t>>USERNAME\n");
    printf("\t\t\t\t\t>>");
    // TAKING USER'S USERNAME INPUT FROM USER //
    scanf("%s", &username);
    printf("\t\t\t\t\t>>PASSWORD:-\n");
    // TAKING USER'S PASSWORD INPUT FROM USER //
    printf("\t\t\t\t\t>>");
    scanf("%s", &pass);


    // CHECKING ENTERED DETAILS //
    // IF ENTERED DATA IS EQUAL TO ADMIN'S INFO OPEN ADMIN FUNCTION //
    if ((strcmp(username, adminusername1) == 0 && strcmp(pass, adminpass1) == 0))
    {
        // OPENS ADMIN PORTALE //
        admin();
    }


    // IF ENTERE DATA IS NOT EQUAL TO ADMIN'S INFO OPEN CUSTOMERS FUNCTION //
    else
    {
        // OPENS CUSTOMER LOGIN PROCESS AND PORTALE //
        customer(username, pass);
    }
    // THE END OF OUR PROJECT SUBMITTED BY SHREY, ABDULLAH AND AMULYA //

    
    return 0;
}