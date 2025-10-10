#include <iostream>
#include <cmath>

using namespace std;

template <typename MUJTYP>
MUJTYP maximum(MUJTYP a, MUJTYP b){
	MUJTYP value;
	if(a > b){
		value = a;
	} else {
		value = b;
	}
	return value;
}

auto maximum2(auto a, auto b){
	auto value = a;
	if(a > b){
		value = a;
	} else {
		value = b;
	}
	return value;
}

int main( void ){

	double a = 10.1;
	double b = 11.1;

	cout << "Maximum je " << maximum(a,b) << endl;
	cout << "Maximum je " << maximum2(a,b) << endl;

	return 0;
}