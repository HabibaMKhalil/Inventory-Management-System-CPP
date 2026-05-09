#  Inventory Management System (C++)  

*A console-based inventory system with customer/product management, sales tracking, and restock alerts*  

##  Features  
- **Product Management**: Add/search products by category (Large/Small/Kitchen Appliances, Gadgets)  
- **Customer Management**: Add/edit customer details (name, email, payment method)  
- **Sales Processing**: Record purchases/returns with automatic stock updates  
- **Inventory Alerts**: Restock recommendations for low-quantity items  
- **File Persistence**: All data saved in `.txt` files (`Customer details.txt`, `Product Names.txt`)  

##  Tech Stack  
- **C++17** (OOP, file handling)  
- Standard Library (`<fstream>`, `<iostream>`, `<string>`)  

##  Files  
- `Programming Project.cpp`: Main program  
- `Customer details.txt`: Customer database  
- `Product Names.txt`: Product catalog (name, price, quantity, category)  

##  How to Run  
1. Clone the repo:  
   ```bash
   git clone https://github.com/your-username/Inventory-Management-System-CPP.git
   ```
2. Compile (G++):
   ```bash
   g++ "Programming Project.cpp" -o inventory
   ```

3. Execute:
   ```bash
   ./inventory
   ```

##  Menu Options
- Add Product
- Search Product
- Browse by Category
- Add/Edit Customer
- Process Purchase/Return
- Restock Alerts

##  Data Structure
class Product {                                
  string name;                             
  int price, amount;                                
  // Methods: NewProduct(), Search(), Category()                                                   
};                               

class Customer : public Product {                      
  string FirstName, LastName, email, payment;                      
  // Methods: AddCustomer(), EditCustomer(), Purchase()                                   
};                       

## 📝 Notes
- Data is stored in plaintext files (no database).
- For production use, consider adding:                                                                     
  -Input validation                          
  -Error handling                               
  -Encryption for sensitive data                                 
