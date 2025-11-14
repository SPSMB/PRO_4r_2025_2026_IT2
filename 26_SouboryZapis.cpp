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

int main(void){

	string jmenoSouboru = "vystup.txt";
	stringstream s1;
	s1 << "Rozhlas" << endl;
	cout << s1.str();
	s1 << "Televize" << endl;
	cout << s1.str();
	s1.str("");
	s1 << "Noviny" << endl;
	s1 << "Casopis" << endl;
	cout << s1.str();
	zapisDoSouboru(jmenoSouboru, s1);

	return 0;
}
