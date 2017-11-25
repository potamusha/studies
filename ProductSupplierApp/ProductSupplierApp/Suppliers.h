#include<vector>
#include<algorithm>

using namespace std;

struct Supplier {
	char code[6];
	char name[25];
	char address[25];
};

void addSupplier();
void printConsole(Supplier supplier);
void printConsole(vector <Supplier> suppliers);
vector <Supplier> convertToVector(Supplier arr[], int length);
void saveToFile(Supplier newSupplier);
void showSuppliers(vector <Supplier> suppliers);
vector<Supplier> readAllSuppliersFromFile();
void supplierMenu();
void menuSortSupplierBy();
void menuFilterSupplierBy();
void deleteSupplierByCode();
bool compareByNameAsc(Supplier sup1, Supplier sup2);
bool compareByNameDesc(Supplier sup1, Supplier sup2);
bool hasSupplierCode(Supplier spl);
bool supplierExistWithCode(char code[]);
Supplier* convertToArray(vector<Supplier> suppliers);
void overWriteTheFile(vector<Supplier> suppliersList);
bool hasCodeMatch(Supplier spl);
bool hasNameMatch(Supplier spl);
