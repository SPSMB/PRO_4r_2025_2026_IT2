#include <iostream>
#include <iomanip>

using namespace std;

int main( void ){
	
	int teplota = 7;

	cout << "Dnes je " << setw(10) << teplota << "°C\n";
	cout << "Dnes je " << setw(10) << right << teplota << "°C\n";
	cout << "Dnes je " << setw(10) << left << teplota << "°C\n";
	cout << "Dnes je " << setw(10) << teplota << "°C\n";
	cout << "Dnes je " << setfill('*') << right << teplota << "°C\n";

	cout << "Zadej jmeno, potvrd enterem a pak prijmeni: ";
	char prvni;
	char druhy;
	cin >> prvni;
	cin.ignore(1000, '\n');
	cin >> druhy;
	cin.ignore(1000, '\n');
	cout << "Vase inicialy jsou " << prvni << druhy << ".\n";

	return 0;
}