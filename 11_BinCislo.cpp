#include <iostream>
#include <iomanip>

using namespace std;

int main( void ){
	
	int bin[32];
	
	int zustatek;
	cout << "Zadejte cislo dekadicky: ";
	cin >> zustatek;
	
	int i = 0;
	int zbytek;
	while(zustatek > 0){
		zbytek = zustatek%2;
		zustatek /= 2;
		bin[i] = zbytek;
		i++;
	}

	cout << "Binarni hodnota: ";
	for(int j = i-1; j>=0; j--){
		cout << bin[j];
	}
	cout << endl;
	return 0;
}