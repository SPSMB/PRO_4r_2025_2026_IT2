#include <iostream>
#include <iomanip>

using namespace std;

int main( void ){
	
	// Kontrola nacteni spravneho vstupu
	int prumer;

	cout << "Zadejte prumer: ";
	cin >> prumer;
	int i = 1;
	while(!cin){
		cout << i << ": Spatne zadana hodnota" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Zadejte znovu: ";
		cin >> prumer;
		i++;
	}

	cout << "Prumer je " << prumer << endl;

	return 0;
}