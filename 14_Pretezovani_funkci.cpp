#include <iostream>

using namespace std;

auto soucet(auto prvni, auto druhy){
	return prvni + druhy;
}

void vypisAdresu(int & a){
	cout << "Funkce1 - Adr1: " << &a << endl;
}

void vypisAdresu(int & a, int & b){
	cout << "Funkce2 - Adr1: " << &a << endl;
	cout << "Funkce2 - Adr2: " << &b << endl;
}

int main( void ){

	int x = 10;
	int y = 30;
	float z1 = 10.3;
	float z2 = 5.6;
	cout << "Main - adresa x: " << &x << endl;
	cout << "Main - adresa y: " << &y << endl;

	vypisAdresu(x);
	vypisAdresu(x, y);

	cout << "Soucet: " << soucet(z1, z2) << endl;
	cout << "TEST" << endl;

	return 0;
}