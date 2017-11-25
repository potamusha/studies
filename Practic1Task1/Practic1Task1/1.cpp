#include<stdio.h>
#include<conio.h>

double Pi1();
double Pi2(double tochnost);
double Pi3(double e); /*ne rabotaet v C*/
double Dlina(double radius);
double Plowad(double radius);

int main() {
	printf("1. Pi = %Lf \n\n", Pi1());

	double tkaka;
	printf("Vvedite tochnost e >");
	scanf("%Lf", &tkaka);
	printf("2. Pi = %Lf \n\n", Pi2(tkaka));
	
	tkaka = 0.1;
	for (int i = 0; i < 6; i++) {
		printf("3.%d Pri e = %f Pi= %Lf \n", i+1, tkaka, Pi2(tkaka));
		tkaka *= 0.1;
	}

	printf("\n 4.Vvedite tochnost e >");
	scanf("%Lf", &tkaka);
	printf("4. Pi = %Lf \n\n", Pi3(tkaka)); /*ne rabotaet bez parametra pochemu to a dolzhno bit Pi3()*/


	double radiusInput;
	printf("\n5. Vvedite radius okruzhnosti > ");
	scanf("%Lf", &radiusInput);
	printf("5.a. Dlina okruzhnosti = %f \n", Dlina(radiusInput));
	printf("5.b Plowad okruzhnosti = %f", Plowad(radiusInput));

	_getch();
}

double Pi1() {
	double result = 0, n = 1, z = 1, e = 0.000001;
	while (1 / n > e)
	{
		result += z * 1 / n;
		n += 2;
		z = -z;
	}
	return result*4;
}

double Pi2(double e) {
	double result = 0, n = 1, z = 1;
	while (1 / n > e)
	{
		result += z * 1 / n;
		n += 2;
		z = -z;
	}
	return result * 4;
}

double Pi3(double e= 0.0001) {
	double result = 0, n = 1, z = 1;
	while (1 / n > e)
	{
		result += z * 1 / n;
		n += 2;
		z = -z;
	}
	return result * 4;
}

double Dlina(double radius) {
	return  2 * Pi1() * radius;
}

double Plowad(double radius) {
	return Pi1() * radius * radius;
}