#include <iostream>

using namespace std;

int main( void ){

	float cislo = 3.9635;
	float * adr_cislo = & cislo;
	cout << "Cislo: " << cislo << endl;
	cout << adr_cislo << endl;

	float & ref1 = cislo;
	float & ref2 = cislo;

	ref2 = 5.7;

	cout << "REF1: " << ref1 << endl;


	return 0;
}