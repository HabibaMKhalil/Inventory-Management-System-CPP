#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Product {
protected:
	string name;
	int price;
public:
	int amount;
	// default constructor
	Product() {
		name = "unknown";
		price = 0;
		amount = 0;
	}
	// class constructor
	Product(string n, int p, int a) {
		name = n;
		price = p;
		amount = a;
	}
	// setters and getters
	void setName(string n) {
		name = n;
	}
	void setPrice(int p) {
		price = p;
	}
	void setAmount(int a) {
		amount = a;
	}
	string getName() {
		return name;
	}
	int getPrice() {
		return price;
	}
	int getAmount() {
		return amount;
	}
	// method for adding a new product to the products file
	void NewProduct(string name, int price, int amount) {
		fstream file;
		file.open("Product Names.txt", ios::app);
		file << "\n" << name << endl;
		file << price << " " << amount;
		cout << "Item added successfully! " << endl;
		cout << endl;
	}
	// method to search for a product from the existing products
	void Search() {
		string productSearch;
		cout << "Enter the product you want to search for\n(include a (-) between each word): ";
		cin >> productSearch;
		string lineProduct, lineDigit, lineCategory; // first line for the product name, second line for the price and amount, third line for the category of the product
		fstream file;
		file.open("Product Names.txt", ios::in); // file containing all products
		while (!file.eof()) {
			getline(file, lineProduct);
			if (lineProduct == productSearch) {
				cout << endl << "Product's name: " << productSearch << endl;
				getline(file, lineDigit);
				// displaying all the product's details
				for (int i = 0; i < lineDigit.length(); i++) {
					if (lineDigit[i] == ' ') {
						// displaying the price of the product - the first number wirtten after the product's name
						cout << "Price: ";
						int count = 0;
						for (int j = 0; j < i; j++) {
							cout << lineDigit[j];
							count++;
						}
						string c = "";
						for (int i = 0; i < count; i++) {
							int x = lineDigit[i] - '0';
							string c1 = to_string(x);
							c += c1;
							price = stoi(c);
						}
						// displaying the number of items left from this product - second number written after the product's name
						cout << endl << "Amount: ";
						int count2 = 0;
						for (int j = i + 1; j < lineDigit.length(); j++) {
							if (isdigit(lineDigit[j])) {
								amount = lineDigit[j] - '0';
								count2++;
							}
							cout << amount;
						}
					}
				}
				getline(file, lineCategory);
				cout << endl << "Category: ";
				for (int i = 0; i < lineCategory.length(); i++) {
					cout << lineCategory[i];
				}
				cout << endl;
			}
		}
		file.close();
		cout << endl;
	}
	void Category() {
		cout << "1) Large-appliances\n2) Small-appliances\n3) Kitchen-appliances\n4) Gadgets\n";
		cout << endl << "Select the category you want to purchase from (1-4): ";
		int Category;
		cin >> Category;
		cout << endl;
		fstream file;
		string product, digits, category;
		file.open("Product Names.txt", ios::in);
		while (!file.eof()) {
			getline(file, product);
			getline(file, digits);
			getline(file, category);
			while (Category < 1 || Category > 4) {
				cout << "Not a category!" << endl;
				cout << endl << "Select the category you want to purchase from (1-4): ";
				cin >> Category;
				cout << endl;
			}
			if (Category == 1) {
				if (category == "Large-appliances") {
					cout << product << endl;
				}
			}
			else if (Category == 2) {
				if (category == "Small-appliances") {
					cout << product << endl;
				}
			}
			else if (Category == 3) {
				if (category == "Kitchen-appliances") {
					cout << product << endl;
				}
			}
			else if (Category == 4) {
				if (category == "Gadgets") {
					cout << product << endl;
				}
			}
		}
		file.close();
		cout << endl;
	}
};
class Customer :public Product {
private:
	string FirstName;
	string LastName;
	string phoneNum;
	string address;
	string email;
	string payment;
public:
	Customer() {
		name = "unknown";
		price = 0;
		amount = 0;
		FirstName = "unknown";
		LastName = "unkown";
		phoneNum = "unknown";
		address = "unknown";
		email = "unknown";
		payment = "unknown";
	}
	void AddCustomer() {
		fstream file;
		file.open("Customer details.txt", ios::app);
		int n;
		cout << "How many customers do you want to add? ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Enter the first name of the customer: ";
			cin >> FirstName;
			file << FirstName << endl;
			cout << "Enter the Last name of the customer: ";
			cin >> LastName;
			file << LastName << endl;
			cout << "Enter the customer's phone number: ";
			cin >> phoneNum;
			file << phoneNum << endl;
			cout << "Enter the customer's address: ";
			cin >> address;
			file << address << endl;
			cout << "Enter the customer's email: ";
			cin >> email;
			file << email << endl;
			cout << "Enter the payment method: ";
			cin >> payment;
			file << payment << endl;
		}
		file.close();
		cout << endl;
	}
	void EditCustomer() {
		string first, last;
		int option;
		cout << "Enter the first name of the customer you want to edit: ";
		cin >> first;
		cout << "Enter the last name of the customer you want to edit: ";
		cin >> last;
		cout << "1)First Name\n2) Last Name\n3) Phone Number\n4) Address\n5) Email Address\n6) Payment Method\n";
		cout << "Select what you want to edit(1-6): ";
		cin >> option;
		fstream file, file2;
		string line;
		int count = 0;
		file.open("Customer details.txt", ios::in);
		while (!file.eof()) {
			getline(file, line);
			count++;
		}
		file.close();
		string fname, lname, phone, Address, Email, Payment, line2;
		string fname2, lname2, phone2, Address2, Email2, Payment2;
		string Fname, Lname, Phone, newAddress, newEmail, newPayment;
		file.open("Customer details.txt", ios::in);
		file2.open("other customer.txt", ios::app);
		int chosenLine = 0;
		getline(file, fname);
		getline(file, lname);
		getline(file, phone);
		getline(file, Address);
		getline(file, Email);
		getline(file, Payment);
		while (!file.eof()) {
			if (first != fname && last != lname) {
				file2 << fname << endl;
				file2 << lname << endl;
				file2 << phone << endl;
				file2 << Address << endl;
				file2 << Email << endl;
				file2 << Payment << endl;
				getline(file, fname);
				getline(file, lname);
				getline(file, phone);
				getline(file, Address);
				getline(file, Email);
				getline(file, Payment);
				chosenLine += 6;
			}
			if (fname == first && lname == last) {
				while (option >= 1 && option <= 6) {
					int x = count - chosenLine;
					if (option == 1) {
						cout << "Enter the new first name: ";
						cin >> Fname;
						file2 << Fname << endl;
						file2 << lname << endl;
						file2 << phone << endl;
						file2 << Address << endl;
						file2 << Email << endl;
						file2 << Payment << endl;
						getline(file, fname);
						getline(file, lname);
						getline(file, phone);
						getline(file, Address);
						getline(file, Email);
						getline(file, Payment);
						break;

					}
					else if (option == 2) {
						cout << "Enter the new last name: ";
						cin >> Lname;
						file2 << fname << endl;
						file2 << Lname << endl;
						file2 << phone << endl;
						file2 << Address << endl;
						file2 << Email << endl;
						file2 << Payment << endl;
						getline(file, fname);
						getline(file, lname);
						getline(file, phone);
						getline(file, Address);
						getline(file, Email);
						getline(file, Payment);
						break;
					}
					else if (option == 3) {
						cout << "Enter the new phone number: ";
						cin >> Phone;
						file2 << fname << endl;
						file2 << lname << endl;
						file2 << Phone << endl;
						file2 << Address << endl;
						file2 << Email << endl;
						file2 << Payment << endl;
						getline(file, fname);
						getline(file, lname);
						getline(file, phone);
						getline(file, Address);
						getline(file, Email);
						getline(file, Payment);
						break;
					}
					else if (option == 4) {
						cout << "Enter the new Address: ";
						cin >> newAddress;
						file2 << fname << endl;
						file2 << lname << endl;
						file2 << phone << endl;
						file2 << newAddress << endl;
						file2 << Email << endl;
						file2 << Payment << endl;
						getline(file, fname);
						getline(file, lname);
						getline(file, phone);
						getline(file, Address);
						getline(file, Email);
						getline(file, Payment);
						break;
					}
					else if (option == 5) {
						cout << "Enter the new email: ";
						cin >> newEmail;
						file2 << fname << endl;
						file2 << lname << endl;
						file2 << phone << endl;
						file2 << Address << endl;
						file2 << newEmail << endl;
						file2 << Payment << endl;
						getline(file, fname);
						getline(file, lname);
						getline(file, phone);
						getline(file, Address);
						getline(file, Email);
						getline(file, Payment);
						break;
					}
					else {
						cout << "Enter the new payment method: ";
						cin >> newPayment;
						file2 << fname << endl;
						file2 << lname << endl;
						file2 << phone << endl;
						file2 << Address << endl;
						file2 << Email << endl;
						file2 << newPayment << endl;
						getline(file, fname);
						getline(file, lname);
						getline(file, phone);
						getline(file, Address);
						getline(file, Email);
						getline(file, Payment);
						break;
					}
				}
				while (option < 1 && option > 6) {
					cout << "Not an option!";
					cout << "1)First Name\n2) Last Name\n3) Phone Number\n4) Address\n5) Email Address\n6) Payment Method\n";
					cout << "Select what you want to edit(1-6): ";
					cin >> option;
				}
			}
		}
		cout << endl;
	}
	void Purchase() {
		string product, line;
		int num;
		cout << "Enter the item you want to purchase: ";
		cin >> product;
		cout << "Enter the number of items: ";
		cin >> num;
		cout << endl;
		fstream file;
		file.open("Product Names.txt", ios::in);
		while (!file.eof()) {
			getline(file, line);
			if (product == line) {
				getline(file, line);
				for (int i = 0; i < line.length(); i++) {
					if (line[i] == ' ') {
						int count = 0;
						for (int j = 0; j < i; j++) {
							count++;
						}
						string c = "";
						for (int i = 0; i < count; i++) {
							int x = line[i] - '0';
							string c1 = to_string(x);
							c += c1;
							price = stoi(c);
						}
						cout << "Price per item: " << price << endl;

						for (int j = i + 1; j < line.length(); j++) {
							if (isdigit(line[j])) {
								amount = line[j] - '0';
								if (amount == 0) {
									cout << "Product out of stock!" << endl;
								}
								else if (amount < num) {
									cout << "You can only purchase " << amount << " or less!" << endl;
								}
								else {
									amount -= num;
									cout << "Updated amount: " << amount << endl;
									int total = price * num;
									cout << "Your total is: " << total << endl;
								}
							}
						}
					}
				}
			}

		}
		cout << endl;
	}
	void RetrunProduct() {
		string product, line;
		int items;
		cout << "Enter the item you want to return: ";
		cin >> product;
		cout << "How many items do you want to return: ";
		cin >> items;
		fstream file;
		file.open("Product Names.txt", ios::in);
		while (!file.eof()) {
			getline(file, line);
			if (product == line) {
				getline(file, line);
				for (int i = 0; i < line.length(); i++) {
					if (line[i] == ' ') {
						int count = 0;
						for (int j = 0; j < i; j++) {
							count++;
						}
						string c = "";
						for (int i = 0; i < count; i++) {
							int x = line[i] - '0';
							string c1 = to_string(x);
							c += c1;
							price = stoi(c);
						}
						cout << "Price per item: " << price << endl;
						cout << "Updated amount: ";
						for (int j = i + 1; j < line.length(); j++) {
							if (isdigit(line[j])) {
								amount = line[j] - '0';
								amount += items;
							}
							cout << amount << endl;
						}
					}
				}
			}
		}
		cout << "Your refund total is: " << price * items << endl;
		cout << endl;
	}
	void CheckRestock() {
		string product, line;
		cout << "Enter the item you want to check for restocking: ";
		cin >> product;
		fstream file;
		file.open("Product Names.txt", ios::in);
		while (!file.eof()) {
			getline(file, line);
			if (product == line) {
				getline(file, line);
				for (int i = 0; i < line.length(); i++) {
					if (line[i] == ' ') {
						for (int j = i + 1; j < line.length(); j++) {
							if (isdigit(line[j])) {
								amount = line[j] - '0';
							}
							if (amount < 3) {
								cout << "Needs restock! Amount Left: " << amount << endl;
							}
							else {
								cout << "Doesn't need restock! Amount Left: " << amount << endl;
							}
						}
					}
				}
			}
		}
		cout << endl;
	}
	void RestockSummary() {
		cout << "Restock!" << endl;
		fstream file;
		string line, line2, Pname;
		file.open("Product Names.txt", ios::in);
		while (!file.eof()) {
			getline(file, line);
			getline(file, line2);
			for (int i = 0; i < line2.length(); i++) {
				if (line2[i] == ' ') {
					for (int j = i + 1; j < line2.length(); j++) {
						if (isdigit(line2[j])) {
							amount = line2[j] - '0';
						}
					}
					if (amount < 3) {
						cout << line << endl << "Amount left: " << amount << endl;
						cout << endl;
					}
				}
			}
		}
		cout << endl;
	}
};

int main() {
	string name;
	int amount, price;
	// ask for the options: 
	cout << "1) Add a new product\n2) Search for a product\n3) Display all products with specific categories\n4) Add a new customer\n5) Edit an existing customer" << endl;
	cout << "6) Record a purchase of a product by a customer\n7) Record the return of a product by a customer\n8) Check if the product needs to be restocked \n9) Restock Summary\n10) Exit application" << endl;
	cout << endl << "Select an option (1-10): ";
	int option;
	cin >> option;
	cout << endl;
	while (option != 10) {
		// if the user didn't select to exit the program
		if (option == 1) {
			// asking user to add a new product
			cout << "Enter a new product: ";
			cin >> name;
			cout << "Enter the price of the product: ";
			cin >> price;
			cout << "Enter the amount of this product: ";
			cin >> amount;
			Product product;
			product.setAmount(amount);
			product.setName(name);
			product.setPrice(price);
			product.getAmount();
			product.getName();
			product.getPrice();
			product.NewProduct(name, price, amount);
		}
		else if (option == 2) {
			// searching for a product
			Product search;
			search.Search();
		}
		else if (option == 3) {
			// Displaying all products from specific category
			Product category;
			category.Category();
		}
		else if (option == 4) {
			// adding a new customer
			Customer c;
			c.AddCustomer();
		}
		else if (option == 5) {
			// edit an existing customer
			Customer c;
			c.EditCustomer();
			remove("Customer details.txt");
			rename("other customer.txt", "Customer details.txt");
		}
		else if (option == 6) {
			// record a purchase
			Customer c;
			c.Purchase();
		}
		else if (option == 7) {
			// record return of a product
			Customer c;
			c.RetrunProduct();
		}
		else if (option == 8) {
			// check restock of a specific product
			Customer c;
			c.CheckRestock();
		}
		else if (option == 9) {
			// display restock summary
			Customer c;
			c.RestockSummary();
		}
		cout << "1) Add a new product\n2) Search for a product\n3) Display all products with specific categories\n4) Add a new customer\n5) Edit an existing customer" << endl;
		cout << "6) Record a purchase of a product by a customer\n7) Record the return of a product by a customer\n8) Check if the product needs to be restocked \n9) Restock Summary\n10) Exit application" << endl;
		cout << endl << "Select an option (1-10): ";
		cin >> option;
		cout << endl;
		if (option > 10 || option < 1) {
			cout << "Not an option!\n";
			cout << "1) Add a new product\n2) Search for a product\n3) Display all products with specific categories\n4) Add a new customer\n5) Edit an existing customer" << endl;
			cout << "6) Record a purchase of a product by a customer\n7) Record the return of a product by a customer\n8) Check if the product needs to be restocked \n9) Restock Summary\n10) Exit application" << endl;
			cout << endl << "Select an option (1-10): ";
			cin >> option;
			cout << endl;
		}
	}
	cout << "Exit successful!" << endl;
	return 0;
}