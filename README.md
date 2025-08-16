# 🛒 Supermarket Management System  

A complete **C-based project** for handling supermarket operations.  
Supports **Admin** and **Customer** modules with proper file handling for permanent data storage.  

---

## ✨ Features  

### 👨‍💼 Admin Panel  
- **Add New Product** → Enter product ID, name, price, quantity, and category  
- **Update Existing Product** → Modify price or stock of an existing product  
- **Delete Product** → Remove products from the inventory  
- **View Product List** → Display all available products with details  
- **View Sales Report** → Check total revenue, sold items, and current stock  
- **Manage Customer Records** → Add, delete, or view registered customers  

---

### 🛍️ Customer Panel  
- **View Products** → See all products available in the supermarket  
- **Search Product** → Find items by product ID or category  
- **Add to Cart** → Select products and store them temporarily in a cart  
- **View Cart** → See items added to cart before checkout  
- **Generate Bill** → Finalize purchase with total amount, tax, and discounts  
- **Save Receipt** → Bill stored in a text file for later reference  

---

### 📂 File Handling System  
- **`products.txt`** → Permanent storage of product database  
- **`customers.txt`** → Stores customer login & registration details  
- **`cartlist.txt`** → Temporary storage for cart during shopping session  
- **`sales.txt`** → Maintains records of all completed transactions  

---

### 🔒 Security & Validation  
- Admin login with **username & password**  
- Customer registration & login system  
- Input validation for product quantity, price, and IDs  

---

## 🏗️ Project Structure  

```plaintext
📦 Supermarket-Management-System
 ├─ 💻 src/                    # Source code files
 │   ├─ main.c                 # Entry point
 │   ├─ admin.c                # Admin functions
 │   ├─ customer.c             # Customer functions
 │   ├─ cart.c                 # Cart & billing
 │   └─ utils.c                # Helper functions
 │
 ├─ 📄 include/                # Header files
 │   ├─ admin.h
 │   ├─ customer.h
 │   ├─ cart.h
 │   └─ utils.h
 │
 ├─ 📦 data/                   # Data storage
 │   ├─ products.txt           # Product database
 │   ├─ customers.txt          # Customer login details
 │   ├─ cartlist.txt           # Temporary cart storage
 │   └─ sales.txt              # Sales records
 │
 ├─ 📑 docs/                   # Documentation
 │   └─ README.md              # Project details
 │
 ├─ 📜 LICENSE                 # License info
 └─ 🏗️ Makefile                 # Compile automation
