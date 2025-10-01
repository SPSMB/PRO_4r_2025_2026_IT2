#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main( void ){
	
	char z1;
	char z2;
	char z3;

	// 1 Nacteni 1 znaku
	cout << "Zadejte text: ";
	cin >> z1;
	z2 = getchar();
	z3 = cin.get();

	cout << ">" << z1 << "<" << endl;
	cout << ">" << z2 << "<" << endl;
	cout << ">" << z3 << "<" << endl;

	// vycisteni vstupu
	cin.ignore(1000, '\n');
	// cin.ignore(); - ignoruje jen 1 znak
	// Nacteni retezce

	char retezec[50];
	cout << "Zadejte delsi text: ";
	// cin >> retezec; // toto nacte text jen do mezery
	cin.getline(retezec, 50);

	cout << "retezec: " << retezec << endl;

	return 0;
}