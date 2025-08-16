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
      printf(BOLD WHITE "OUR STOCK\n"RESET);
      // MAKING STRING FOR DISPLAYING //
      char data[50];
      // OPENING PRODUCT FILE //
      FILE *displayfile = fopen("products.txt", "r");
      // PRINTING PRODUCTS IN TABULAR FORM //
      printf(CYAN"\t\tS NO.\t||\tNAME\t\t|\tPRICE\t|\tQUANTITY\n" RESET);
      // FETCHING DATA LINE BY LINE //
      for (int i = 1; fgets(data, sizeof(data), displayfile) != NULL; i++)
      {
          // MAKING VARIABLES TO STORE DATA //
          char productName[20];
          int price;
          // FETCHING DATA FROM FILE //
          sscanf(data, "%s %d %d", &productName, &price);
          // PRINTING PRODUCTS IN TABULAR FORM //
          printf( BOLD CYAN"\t\t%d.\t||\t%s\t\t|\tRs.%d\t|\tunlimited\n"RESET, i, productName, price);
      }
  }
  // PRODUCTS ARE DISPLAYED FROM THE FILE //


  // ADD PRODUCT //
  void addProduct()
  {
      // MAKING VARIABLE FOR INPUTING NEW PRODUCT DATA //
      char name[20];
      int price;
      // INPUTING //
      printf(CYAN"Enter product name: "RESET);
      scanf("%s", &name);
      printf(CYAN"Enter product price: "RESET);
      scanf("%d", &price);
      printf(GREEN"Product has been added successfully!\n"RESET);
      // OPENING FILE AND ADDING NEW PRODUCT DATA IN FILE //
      FILE *fptr = fopen("products.txt", "a");
      fprintf(fptr, "%s %d\n", name, price);
      fclose(fptr);
  }
  // PRODUCT IS ADDED IN FILE //


  // DELETE ANY ONE PRODUCT //
  void deleteProduct()
  {
      printf(CYAN"Enter product name to delete:"RESET);
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


      printf(GREEN"Your product has been deleted successfully!\n"RESET);
  }
  // PRODUCT IS DELETED FROM OUR STOCK //


  // ADMIN'S FUNCTION //
  void admin()
  {
      // POPUP FOR ADMIN //
      printf(CYAN BOLD"Welcome back, Admin !\n"RESET);
      int adminChoice;
      do
      {
          // PRESSING DETAILS FOR ADMIN //
          printf(YELLOW"Press 0 for exit\n");
          printf("Press 1 to display items\n");
          printf("Press 2 to add items\n");
          printf("Press 3 to delete items\n");
          printf("Enter number:"RESET);
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
                  printf(RED"Wrong password. Please try again."RESET);
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
      printf(YELLOW BOLD"OUR STOCK\n"RESET);
      // MAKING STRING FOR DISPLAYING //
      char data[50];
      FILE *displayfile = fopen("cartlist.txt", "r");
      printf(BOLD CYAN"\t\tS NO.\t\t||\tNAME\t\t|\tQUANTITY\n" RESET);
      for (int i = 1; fgets(data, sizeof(data), displayfile) != NULL; i++)
      {
          char productName[20];
          int quantity;
          sscanf(data, "%s %d %d", &productName, &quantity);
          printf(WHITE"\t\t%d.\t\t||\t%s\t\t|\t%d\n"RESET, i, productName, quantity);
      }
  }
  // PRODUCTS ARE DISPLAYED FROM THE FILE //


  // ADD PRODUCT //
  void addcart()
  {


      char name[20];
      int price, quantity;
      printf(WHITE"Enter product name:");
      scanf("%s", &name);
      printf(WHITE"Enter product quantity:"RESET);
      scanf("%d", &quantity);
      printf(GREEN ITALIC"Your product has been added to your cart successfully!\n"RESET);
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
      printf(CYAN BOLD"\t\tS NO.\t||\tNAME\t\t|\tQUANTITY\t|\tPRICE\n"RESET);
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
                  printf(WHITE BOLD"\t\t%d.\t||\t%s\t\t|\t%d\t|\t\t%.2f\n"RESET, i, nm, quantity, totalPrice);
              }
          }


          rewind(a);
          // we get the price from this code //
      }
      printf(GREEN"Net price Rs%.2f\n", netPrice);
      printf("Including 18%c GST:Rs%.2f\n", '%', netPrice * 0.18);
      printf("Grand price:Rs%.2f\n"RESET, (netPrice + (netPrice * 0.18)));
      fclose(f);
      fclose(a);
    remove("cartlist.txt");
    exit(0);
  }


  // CUSTOMER'S FUNCTION WITH TWO INFO USERNAME AND PASSWORD //
  void customer(char name[], char pass[])
  {
      // USING BOOLEAN FUNCTION IN IF CONDITION IF TRUE IF CONDITION WORKS AND FALSE ELSE CONDITION WORK //


      // TRUE //
      if (userAvailable(name, pass))
      {
          // TRUE MEANS OLD CUSTOMER //
          printf(MAGENTA BOLD"Glad to have you back, WELCOME!\n"RESET);
      }


      // FLASE //
      else
      {
          // FALSE MEANS NEW CUSTOMER THEN SAVING THE DATA OF CUSTOMER IN CUSTOMER'S FILE //
          printf(CYAN BOLD"You seem to be a new user\n"RESET);
          // ADDING USER INFO IN CUSTOMER'S FILE //
          FILE *fptr = fopen("customers.txt", "a");
          fprintf(fptr, "%s %s\n", name, pass);
          fclose(fptr);
          printf(GREEN"You have been added to our system successfully!\n"RESET);
          // ADDED //
      }
      int customerChoice;
      do
      {
          // PRESSING DETAILS FOR ADMIN //
          printf(YELLOW"Press 0 for exit\n");
          printf("Press 1 to display stock\n");
          printf("Press 2 to add to cart\n");
          printf("Press 3 to display your cart\n");
          printf("Press 4 to display bill\n");
          printf("Enter number:"RESET);
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
      printf(YELLOW ITALIC BOLD"----------------------Welcome to SPORTLINE SPREE - your one stop destination for all types of sport items-----------------------\n"RESET);


      // ADMIN DETAILS //
      char adminusername1[30] = "shrey.sircar", adminpass1[20] = "shrey@123";
      char adminusername2[30] = "sheikh.abdullah", adminpass2[20] = "sheikh@123";
      char adminusername3[30] = "amulya.kaushik", adminpass3[20] = "amulya@123";
      // MAKING TWO STRINGS TO STORE DATA ENTERED BY USERNAME AND PASSWORD //
      char username[30], pass[20];
      printf(CYAN"Enter username:\n"RESET);
      // TAKING USER'S USERNAME INPUT FROM USER //
      scanf("%s", &username);
      printf(CYAN"Enter password:\n"RESET);
      // TAKING USER'S PASSWORD INPUT FROM USER //
      scanf("%s", &pass);


      // CHECKING ENTERED DETAILS //
      // IF ENTERED DATA IS EQUAL TO ADMIN'S INFO OPEN ADMIN FUNCTION //
      if ((strcmp(username, adminusername1) == 0 && strcmp(pass, adminpass1) == 0) || (strcmp(username, adminusername2) == 0 && strcmp(pass, adminpass2) == 0) || (strcmp(username, adminusername3) == 0 && strcmp(pass, adminpass3) == 0))
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
