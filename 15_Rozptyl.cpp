#include <iostream>
#include <cmath>

using namespace std;

auto prumer(auto a, auto b){
	return (a+b)/2;
}

auto prumer(auto a, auto b, auto c){
	return (a+b+c)/3;
}

auto rozptyl(auto a, auto b){
	auto p = prumer(a,b);
	auto rozptyl = (pow(a-p,2) + pow(b-p,2))/2;
	return rozptyl;
}

auto rozptyl(auto a, auto b, auto c){
	auto p = prumer(a,b,c);
	auto rozptyl = (pow(a-p,2) + pow(b-p,2) 
		+ pow(c-p,2) )/3;
	return rozptyl;
}

int main( void ){

	int a, b, c;
	cout << "Zadej 3 cisla: ";
	cin >> a >> b >> c;

	cout << "rozptyl: " << rozptyl(a, b, c) << endl;

	return 0;
}