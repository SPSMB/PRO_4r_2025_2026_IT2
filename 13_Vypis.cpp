#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;


int main( void ){

	/*
	double x = 2.9876543210;
	cout << "x3: " << fixed << setprecision(10) 
		 << x << endl;

	x*=100;
	x = round(x);
	cout << "x1: " << x << endl;
	x/=100;
	cout << "x2: " << x << endl;
	*/

	char pole[] = {'a', 'b', 'c', 'd'};
	for(char x : pole){
		cout << x;
	}
	cout << endl;

	return 0;
}