#include "Suppliers.h"
#include<iostream>
#include<string>

char supplierCode[6];
char supplierName[25];

void addSupplier() {
	cout << endl << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "                             Add Supplier                            " << endl;
	cout << "---------------------------------------------------------------------" << endl;
	Supplier newSupplier;
	cout << "Please enter supplier" << endl;

	cout << "(1/3) Code : ";
	cin >> newSupplier.code;

	cout << "(2/3) Name : ";
	string nameSpl;
	cin.ignore();
	getline(cin, nameSpl);
	strncpy(newSupplier.name, nameSpl.c_str(), sizeof(newSupplier.name));
		
	cout << "(3/3) Address : ";
	string address;
	getline(cin, address);
	strncpy(newSupplier.address, address.c_str(), sizeof(newSupplier.address));
	cout << endl;
	
	saveToFile(newSupplier);
	cout << "Supplier record has been saved successfully" << endl;

}

void printConsole(Supplier supplier) {
	cout << supplier.code << "\t" << supplier.name << "\t" << supplier.address << endl;
}

void printConsole(vector <Supplier> suppliers) {
	cout << endl << endl;
	cout << "----------------------------- SUPPLIERS -----------------------------" << endl;
	cout << "Code" << "\t" << "Name" << "\t" << "Address" << endl << endl;
	for (int i = 0; i < suppliers.size(); i++) {
		printConsole(suppliers[i]);
	}
	cout << endl;
	cout << "Suppliers found: " << suppliers.size();

}

vector <Supplier> convertToVector(Supplier arr[], int length) {
	vector <Supplier> suppliers;
	for (int i = 0; i < length; i++) {
		suppliers.push_back(arr[i]);
	}
	return suppliers;
}

void saveToFile(Supplier newSupplier) {
	FILE *fp = fopen("suppliers.dat", "a+b");
	fwrite(&newSupplier, sizeof(Supplier), 1, fp);
	fclose(fp);
}

void showSuppliers(vector<Supplier> suppliers) {
	printConsole(suppliers);
	supplierMenu();
}

vector<Supplier> readAllSuppliersFromFile() {
	FILE *fp = fopen("suppliers.dat", "rb");
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp) / sizeof(Supplier);
	Supplier *suppliersArray = new Supplier[size];
	rewind(fp);
	fread(suppliersArray, sizeof(Supplier), size, fp);
	fclose(fp);
	return convertToVector(suppliersArray, size);
}

void supplierMenu() {
	cout << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "                         Supplier menu (1-3)                         " << endl;
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
		menuSortSupplierBy();
		break;
	}
	case '2':
	{
		menuFilterSupplierBy();
		break;
	}
	case '3':
	{
		deleteSupplierByCode();
		break;
	}
	}
}

void menuSortSupplierBy() {
	cout << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "                        Supplier sort by (1-2)                       " << endl;
	cout << "---------------------------------------------------------------------" << endl
		<< "                                                    1 - name ascending" << endl
		<< "                                                  2 -  name descending" << endl
		<< "                                 any other key - back to Supplier menu" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	char response;
	cin >> response;
	switch (response) {
	case '1':
	{
		vector<Supplier> suppliers = readAllSuppliersFromFile();
		sort(suppliers.begin(), suppliers.end(), compareByNameAsc);
		showSuppliers(suppliers);
		break;
	}
	case '2':
	{
		vector<Supplier> suppliers = readAllSuppliersFromFile();
		sort(suppliers.begin(), suppliers.end(), compareByNameDesc);
		showSuppliers(suppliers);
		break;
	}
	default: {
		supplierMenu();
		break;
	}
	}
}

void menuFilterSupplierBy() {
	cout << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "                      Supplier filter by (1-2)                       " << endl;
	cout << "---------------------------------------------------------------------" << endl
		<< "                                                              1 - code" << endl
		<< "                                                             2 -  name" << endl
		<< "                                 any other key - back to Supplier menu" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	char response;
	cin >> response;
	switch (response) {

	case '1':
	{
		cout << "Enter code:  ";
		cin >> supplierCode;
		vector<Supplier> suppliers = readAllSuppliersFromFile();
		vector<Supplier>::iterator it = find_if(suppliers.begin(), suppliers.end(), hasCodeMatch);
		vector<Supplier> filteredSuppliers;
		while (it != suppliers.end()) {
			filteredSuppliers.push_back(*it);
			it = find_if(++it, suppliers.end(), hasCodeMatch);
		}
		showSuppliers(filteredSuppliers);
		break;
	}
	case '2':
	{
		cout << "Enter name:  ";
		cin >> supplierName;
		vector<Supplier> suppliers = readAllSuppliersFromFile();
		vector<Supplier>::iterator it = find_if(suppliers.begin(), suppliers.end(), hasNameMatch);
		vector<Supplier> filteredSuppliers;
		while (it != suppliers.end()) {
			filteredSuppliers.push_back(*it);
			it = find_if(++it, suppliers.end(), hasNameMatch);
		}
		showSuppliers(filteredSuppliers);
		break;
	}
	default: {
		supplierMenu();
		break;
	}
	}

}

void deleteSupplierByCode() {
	cout << "---------------------------------------------------------------------" << endl;
	cout << "                        Supplier delete by code                      " << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Enter code: ";
	cin >> supplierCode;
	vector<Supplier> suppliersList = readAllSuppliersFromFile();

	vector<Supplier>::iterator it = find_if(suppliersList.begin(), suppliersList.end(), hasSupplierCode);
	if (it == suppliersList.end()) {
		cout << endl << "No match found" << endl;
		supplierMenu();
	}
	else {
		cout << endl << endl;
		cout << "------------------ You are about to delete this record ------------------" << endl;
		cout << "Code     " << "\t" << "Name          " << "\t" << "Address              " << endl << endl;
		printConsole(*it);
		cout << endl << "Are you sure you want to delete (Y/N)?";
		char answer;
		cin >> answer;
		if (answer == 'Y' || answer == 'y') {
			suppliersList.erase(it);
			overWriteTheFile(suppliersList);
			cout << "The record has been succesfuly deleted" << endl;
			showSuppliers(readAllSuppliersFromFile());
		}
		else {
			supplierMenu();
		}
	}
}

bool supplierExistWithCode(char code[]) {
	vector <Supplier> suppliers = readAllSuppliersFromFile();
	strncpy(supplierCode, code, sizeof(code));
	vector<Supplier>::iterator it = find_if(suppliers.begin(), suppliers.end(), hasSupplierCode);
	if (it == suppliers.end()) {
		return false;
	}
	return true;
}

Supplier* convertToArray(vector<Supplier> suppliers) {
	int size = suppliers.size();
	Supplier* arraySuppliers = new Supplier[size];

	for (int i = 0; i < size; i++) {
		arraySuppliers[i] = suppliers[i];
	}
	return arraySuppliers;
}

void overWriteTheFile(vector<Supplier> suppliersList) {
	int size = suppliersList.size();
	Supplier* newSuppliers = convertToArray(suppliersList);

	FILE *fp = fopen("suppliers.dat", "wb");
	fwrite(newSuppliers, sizeof(Supplier), size, fp);
	fclose(fp);
}

bool compareByNameAsc(Supplier sup1, Supplier sup2) {
	if (strcmp(sup1.name, sup2.name) < 0) {
		return true;
	}
	return false;
}

bool compareByNameDesc(Supplier sup1, Supplier sup2) {
	if (strcmp(sup1.name, sup2.name) > 0) {
		return true;
	}
	return false;
}


bool hasSupplierCode(Supplier spl) {
	if (strcmp(spl.code, supplierCode) == 0) {
		return true;
	}
	return false;
}

bool hasCodeMatch(Supplier spl) {
	if (strncmp(spl.code, supplierCode, strlen(supplierCode)) == 0) {
		return true;
	}
	return false;
}

bool hasNameMatch(Supplier spl) {
	if (strncmp(spl.name, supplierName, strlen(supplierName)) == 0) {
		return true;
	}
	return false;
}
