#include "Products.h"
#include "Suppliers.h"
#include<iostream>
#include<string>
#include<iomanip>

char productCode[6];
char productSupplierCode[6];
char productName[25];
double productMinPrice;
double productMaxPrice;

void addProduct() {
	cout << endl << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "                             Add Product                             " << endl;
	cout << "---------------------------------------------------------------------" << endl;
	Product newProduct;
	cout << "Please enter product" << endl;

	cout << "(1/6) Code : ";
	cin >> newProduct.code;

	cout << "(2/6) Name : ";
	string namePrd;
	cin.ignore();
	getline(cin, namePrd);
	strncpy(newProduct.name, namePrd.c_str(), sizeof(newProduct.name));

	cout << "(3/6) Unit : ";
	cin >> newProduct.unit;
	
	newProduct.price = validateDouble("(4/6) Price : ");
	newProduct.quantity = validateDouble("(5/6) Quantity : ");
	
	cout << "(6/6) Supplier code : ";
	cin >> newProduct.supplierCode;
	
	if (!supplierExistWithCode(newProduct.supplierCode)) {
		cout << "Supplier code '" << newProduct.supplierCode << "' doesn't exist in the system" << endl;
		cout << "Please add supplier first!" << endl;
	} 
	else {
		saveToFile(newProduct);
		cout << "Product record has been saved successfully" << endl;
	}
}

double validateDouble(string askMessage) {
	double x;
	while (1) {
		cout << askMessage;
		if (cin >> x) {
			break;
		}
		else {
			cout << "Invalid input! Please input a double value" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
	}
	return x;
}

void printConsole(Product product) {
	cout << product.code << "\t" << product.name << "\t" << product.unit << "\t" << product.price << "\t" << product.quantity << "\t" << product.supplierCode << endl;
}

void printConsole(vector <Product> products) {
	cout << endl << endl;
	cout << "----------------------------- PRODUCTS -----------------------------" << endl;
	cout << "Code" <<"\t" << "Name" << "\t" << "Unit" << "\t" << "Price" << "\t" << "Quantity" << "\t" << "Supplier code" << endl << endl;
	for (int i = 0; i < products.size(); i++) {
		printConsole(products[i]);
	}
	cout << endl;
	cout << "Products found: " << products.size();

}

vector <Product> convertToVector(Product arr[], int length) {
	vector <Product> products;
	for (int i = 0; i < length; i++) {
		products.push_back(arr[i]);
	}
	return products;
}


void saveToFile(Product newProduct) {
	FILE *fp = fopen("products.dat", "a+b");
	fwrite(&newProduct, sizeof(Product), 1, fp);
	fclose(fp);
}


void showProducts(vector<Product> products) {
	printConsole(products);
	productsMenu();
}

vector<Product> readAllProductsFromFile() {
	FILE *fp = fopen("products.dat", "rb");
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp) / sizeof(Product);
	Product *productsArray = new Product[size];
	rewind(fp);
	fread(productsArray, sizeof(Product), size, fp);
	fclose(fp);
	return convertToVector(productsArray, size);
}

void productsMenu() {
	cout << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "                         Products menu (1-3)                         " << endl;
	cout << "---------------------------------------------------------------------" << endl
		<< "                                                          1 - sort by " << endl
		<< "                                                         2- filter by " << endl
		<< "                                                   3 - delete by code " << endl
		<< "                                    any other key - back to main menu " << endl;
	cout << "---------------------------------------------------------------------" << endl;
	char response;
	cin >> response;
	switch (response) {
	case '1':
	{
		menuSortProductBy();
		break;
	}
	case '2':
	{
		menuFilterProductBy();
		break;
	}
	case '3':
	{
		deleteProductByCode();
		break;
	}
	}
}

void menuSortProductBy() {
	cout << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "                        Product sort by (1-3)                        " << endl;
	cout << "---------------------------------------------------------------------" << endl
		<< "                                                              1 - name" << endl
		<< "                                           2 -  name and supplier code" << endl
		<< "                                                   3 -  price and name" << endl
		<< "                                  any other key - back to Product menu" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	char response;
	cin >> response;
	switch (response) {
	case '1':
	{
		vector<Product> products = readAllProductsFromFile();
		sort(products.begin(), products.end(), compareByProductNameAsc);
		showProducts(products);
		break;
	}
	case '2':
	{
		vector<Product> products = readAllProductsFromFile();
		sort(products.begin(), products.end(), compareByNameAndSupplierCode);
		showProducts(products);
		break;
	}
	case '3':
	{
		vector<Product> products = readAllProductsFromFile();
		sort(products.begin(), products.end(), compareByPriceAndName);
		showProducts(products);
		break;
	}

	default: {
		productsMenu();
		break;
	}
	}
}

void menuFilterProductBy() {
	cout << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "                      Product filter by (1-3)                        " << endl;
	cout << "---------------------------------------------------------------------" << endl
		<< "                                                              1 - name" << endl
		<< "                                                       2 - price range" << endl
		<< "                                                    3 -  supplier code" << endl
		<< "                                  any other key - back to Product menu" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	char response;
	cin >> response;
	switch (response) {

	case '1':
	{
		cout << "Enter name:  ";
		cin >> productName;
		vector<Product> products = readAllProductsFromFile();
		vector<Product>::iterator it = find_if(products.begin(), products.end(), hasProductNameMatch);
		vector<Product> filteredProducts;
		while (it != products.end()) {
			filteredProducts.push_back(*it);
			it = find_if(++it, products.end(), hasProductNameMatch);
		}
		showProducts(filteredProducts);

		break;
	}

	case '2':
	{
		cout << "Enter price range from:  ";
		cin >> productMinPrice;
		cout << "Enter price range to:  ";
		cin >> productMaxPrice;
		vector<Product> products = readAllProductsFromFile();
		vector<Product>::iterator it = find_if(products.begin(), products.end(), hasPriceMatch);
		vector<Product> filteredProducts;
		while (it != products.end()) {
			filteredProducts.push_back(*it);
			it = find_if(++it, products.end(), hasPriceMatch);
		}
		sort(filteredProducts.begin(), filteredProducts.end(), compareByProducPrice);
		showProducts(filteredProducts);
		break;
	}

	case '3':
	{
		cout << "Enter Supplier code:  ";
		cin >> productSupplierCode;
		vector<Product> products = readAllProductsFromFile();
		vector<Product>::iterator it = find_if(products.begin(), products.end(), hasSupplierCodeMatch);
		vector<Product> filteredProducts;
		while (it != products.end()) {
			filteredProducts.push_back(*it);
			it = find_if(++it, products.end(), hasSupplierCodeMatch);
		}
		sort(filteredProducts.begin(), filteredProducts.end(), compareByProductNameAsc);
		showProducts(filteredProducts);
		break;
	}
	default: {
		productsMenu();
		break;
	}
	}


}

void deleteProductByCode() {
	cout << "---------------------------------------------------------------------" << endl;
	cout << "                        Product delete by code                       " << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Enter code: ";
	cin >> productCode;
	vector<Product> productsList = readAllProductsFromFile();

	vector<Product>::iterator it = find_if(productsList.begin(), productsList.end(), hasProductCode);
	if (it == productsList.end()) {
		cout << endl << "No match found" << endl;
		productsMenu();
	}
	else {
		cout << endl << endl;
		cout << "------------------ You are about to delete this record ------------------" << endl;
		cout << "Code" << "\t" << "Name" << "\t" << "Unit" << "\t" << "Price" << "\t" << "Quantity" << "\t" << "Supplier code" << endl << endl;
		printConsole(*it);
		cout << endl << "Are you sure you want to delete (Y/N)?";
		char answer;
		cin >> answer;
		if (answer == 'Y' || answer == 'y') {
			productsList.erase(it);
			overWriteTheFile(productsList);
			cout << "The record has been succesfuly deleted" << endl;
			showProducts(readAllProductsFromFile());
		}
		else {
			productsMenu();
		}
	}
}

void overWriteTheFile(vector<Product> productsList) {
	int size = productsList.size();
	Product* newProducts = convertToArray(productsList);

	FILE *fp = fopen("products.dat", "wb");
	fwrite(newProducts, sizeof(Product), size, fp);
	fclose(fp);
}

Product* convertToArray(vector<Product> products) {
	int size = products.size();
	Product* arrayProducts = new Product[size];
	for (int i = 0; i < size; i++) {
		arrayProducts[i] = products[i];
	}
	return arrayProducts;
}

bool hasProductCode(Product prd) {
	if (strcmp(prd.code, productCode) == 0) {
		return true;
	}
	return false;
}

bool compareByProductNameAsc(Product prd1, Product prd2) {
	if (strcmp(prd1.name, prd2.name) < 0) {
		return true;
	}
	return false;
}

bool compareByNameAndSupplierCode(Product prd1, Product prd2) {
	if (strcmp(prd1.name, prd2.name) < 0) {
		return true;
	}
	else if (strcmp(prd1.name, prd2.name) == 0 && strcmp(prd1.supplierCode, prd2.supplierCode) < 0) {

		return true;
	}
	return false;
}

bool compareByPriceAndName(Product prd1, Product prd2) {
	if (prd1.price < prd2.price){
		return true;
	}
	else if (prd1.price == prd2.price && strcmp(prd1.name, prd2.name) < 0) {

		return true;
	}
	return false;
}

bool hasProductNameMatch(Product prd) {
	if (strncmp(prd.name, productName, strlen(productName)) == 0) {
		return true;
	}
	return false;
}

bool hasSupplierCodeMatch(Product prd) {
	if (strncmp(prd.supplierCode, productSupplierCode, strlen(productSupplierCode)) == 0) {
		return true;
	}
	return false;
}

bool hasPriceMatch(Product prd) {
	if (prd.price>=productMinPrice && prd.price <= productMaxPrice) {
		return true;
	}
	return false;
}

bool compareByProducPrice(Product prd1, Product prd2) {
	if (prd1.price < prd2.price) {
		return true;
	}
	return false;
}