#include <iostream>
#include <string>

using namespace std;


int main( void ){

	string poleS[10] = {
		string("deleted C:/Users/Tom/jedna.txt 2021-05-20"),
		string("created C:/Users/Tom/dva.txt 2021-05-11"),
		string("new C:/Users/Tom/tri.txt 2021-06-20"),
		string("created C:/Users/Tom/ctyri.txt 2021-07-03"),
		string("updated C:/Users/Tom/pet.txt 2021-07-03"),
		string("new C:/Users/Tom/sest.txt 2021-05-20"),
		string("deleted C:/Users/Tom/sedm.txt 2021-05-11"),
		string("new C:/Users/Tom/osm.txt 2021-05-20"),
		string("updated C:/Users/Tom/devet.txt 2021-05-11"),
		string("updated C:/Users/Tom/deset.txt 2021-07-03") 
	};

	int den, mesic, rok;
	cout << "Zadejte den: ";
	cin >> den;
	cout << "Zadejte mesic: ";
	cin >> mesic;
	cout << "Zadejte rok: ";
	cin >> rok;

	string datum = to_string(rok) + "-";
	if(mesic < 10){
		datum = datum + "0" + to_string(mesic) + "-";
	} else {
		datum = datum + to_string(mesic) + "-";
	}
	if(den < 10){
		datum = datum + "0" + to_string(den);
	} else {
		datum = datum + to_string(den);		
	}
	
	cout << "Vysledky vyhledavani pro datum " 
		 << datum << ":" << endl;
	int cislo = 0; 
	for(int i = 0; i < 10; i++){
		if(poleS[i].find(datum) != string::npos){
			// neco se naslo
			cout << " " << poleS[i] << endl;
		} else {
			cislo++;
		}
	}
	if(cislo == 10){
		cout << "Nic se nenaslo." << endl;
	}

	return 0;
}