#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(void){

	stringstream s1;
	s1 << "Rozhlas" << endl;
	cout << s1.str();

	s1 << "Televize" << endl;
	cout << s1.str();

	s1.str(""); // vymazu obsah streamu
	s1 << "Internet" << endl;
	cout << s1.str();

	return 0;
}
