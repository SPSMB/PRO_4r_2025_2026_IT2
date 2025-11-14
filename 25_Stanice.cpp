#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void zapisDoSouboru(string jmenoSouboru, stringstream & s1){
	ofstream f2(jmenoSouboru);
	if(f2.is_open()){
		f2 << s1.str(); // cely obsah streamu poslu do souboru
	} else {
		cout << "Soubor " << jmenoSouboru 
			 << " se nepovedlo otevrit." << endl; 
	}

	f2.close();
}

void nactiStanice(string jmenoSouboru, stringstream & s1){
	ifstream f1(jmenoSouboru);
	string radek;
	int counter = 0;
	int praha = 0;
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
			s1 << jmeno << " (" << id << ")" << endl;
			praha++;
		}	
	}
	cout << "Pocet vsech stanic je " << counter << endl;
	cout << "Pocet prazskych stanic je " << praha << endl;
	f1.close();
}


int main(void){

	stringstream s1;
	string souborVstup = "25_Stanice_slovnik_2025.csv";
	string souborVystup = "25_Vystup.txt";
	nactiStanice(souborVstup, s1);
	zapisDoSouboru(souborVystup, s1);

	return 0;
}
