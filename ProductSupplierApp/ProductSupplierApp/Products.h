#include<vector>
#include<algorithm>

using namespace std;

struct Product {
	char code[6];
	char name[50];
	char unit[5];
	double price;
	double quantity;
	char supplierCode[6];
};

void addProduct();
void printConsole(Product product);
void printConsole(vector<Product> products);
vector <Product> convertToVector(Product arr[], int length);
void saveToFile(Product newProduct);
vector<Product> readAllProductsFromFile();
void productsMenu();
void menuSortProductBy();
void menuFilterProductBy();
void deleteProductByCode();
void overWriteTheFile(vector<Product> productsList);
Product* convertToArray(vector<Product> products);
bool hasProductCode(Product prd);
void showProducts(vector<Product> products);
bool compareByProductNameAsc(Product prd1, Product prd2);
bool compareByNameAndSupplierCode(Product prd1, Product prd2);
bool compareByPriceAndName(Product prd1, Product prd2);
bool hasProductNameMatch(Product prd);
bool hasSupplierCodeMatch(Product prd);
bool hasPriceMatch(Product prd);
bool compareByProducPrice(Product prd1, Product prd2);
double validateDouble(string askMessage);

