#include <iostream>
#include <iomanip>

using namespace std;

int main( void ){

	auto polomer = 9.168123456848;
	auto * u_r = &polomer;
	cout << "u_r: " << u_r << endl;
	//u_r = sirka;
	//cout << "u_r: " << u_r << endl;

	cout << setbase(10) << 0b1111100 << endl;
	cout << setw(10) << setfill('.')
		 << setprecision(3) << polomer << endl;

	return 0;
}