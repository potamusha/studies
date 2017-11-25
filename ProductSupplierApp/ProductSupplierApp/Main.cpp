#include<iostream>
#include<vector>
#include<algorithm>
#include "Suppliers.h"
#include "Products.h"
#include<string>
#include<cstdio>
#include<stdio.h>
#include<conio.h>

using namespace std;

char menu();

int main(){
	
	char menuNumber;
	do {
		menuNumber = menu();
		switch (menuNumber) {
			case '1':
			{
				addSupplier();
				break;
			}
			case '2':
			{
				addProduct();
				break;
			}
			case '3':
			{
				vector<Supplier> suppliers = readAllSuppliersFromFile();
				showSuppliers(suppliers);
				break;
			}
			case '4':
			{
				vector<Product> products = readAllProductsFromFile();
				showProducts(products);
				break;
			}
		}

	} while (menuNumber == '1' || menuNumber == '2' || menuNumber == '3' || menuNumber == '4');

	return 0;
}

char menu()
{
	cout << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "                     Please choose a menu (1-4)                      " << endl;
	cout << "---------------------------------------------------------------------" << endl
		<< "                                              1 - add a new Supplier" << endl
		<< "                                              2 - add a new Product " << endl
		<< "                                              3 - show all suppliers" << endl
		<< "                                              4 - show all products" << endl
		<< "                                              any other key - exit"<<endl;
	cout << "---------------------------------------------------------------------" << endl;
	char m;
	cin >> m;
	return m;
}



	

	


	
