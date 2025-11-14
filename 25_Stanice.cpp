#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void nactiStanice(string jmenoSouboru){
	ifstream f1(jmenoSouboru);
	string radek;
	int counter = 0;
	if(!f1.is_open()){
		cout << "Nepovedlo se otevrit soubor " << jmenoSouboru 
			 << ". Program se ukonci." << endl;
		return;
	}
	while(getline(f1, radek)){
		if(radek.size() == 0){
			continue;
		}
		counter++;
		if(radek.find("Praha") != string::npos){
			string id = radek.substr(0,5);
			string jmeno = radek.substr(6);
			cout << jmeno << " (" << id << ")" << endl;
		}	
	}
	cout << "Pocet vsech stanic je " << counter << endl;
	f1.close();
}


int main(void){

	string jmenoSouboru = "25_Stanice_slovnik_2025.csv";
	nactiStanice(jmenoSouboru);

	return 0;
}
