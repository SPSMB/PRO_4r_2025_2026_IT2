#include <iostream>
#include <iomanip>

using namespace std;

int main( void ){
	
	// Range-based for
	int pole[] = {1,3,5,7,9};
	for(const int & x : pole){
		cout << x << ",";
	}
	cout << endl;

	char bin[30] = "11111111110000000000111111111";
	for (char & k : bin){
		k = '0';
	}
	cout << bin << endl;
	return 0;
}