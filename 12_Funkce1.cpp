#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void clickText(string text, 
	string area = "FULL", int fontsize = 28){

	if(area == ""){
		area = "FULL";
	}

	// Tady bude logika klikani
	cout << "Klikam na text \"" << text 
		 << "\" v prostoru " << area
		 << " o velikosti " << fontsize << " b."
		 << endl;
}

int main( void ){

	clickText("Pneu", "RADEK1", 35);
	clickText("Svetla", "RADEK5");
	clickText("Nastaveni");
	clickText("Sterace", "", 40);

	return 0;
}