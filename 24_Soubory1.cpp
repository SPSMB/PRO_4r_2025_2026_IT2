#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){

	ifstream f1("24_test.txt", ifstream::in);
	string s1, s2, s3;
	string radek;
	char z1,z2;

	/*
	f1 >> s1 >> s2 >> s3;
	f1.get(z1);
	f1.get(z2);
	getline(f1, radek);
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "z1: " << z1 << endl;
	cout << "z2: " << z2 << endl;
	cout << "radek: " << radek << endl;
	*/
	while(f1 >> s1){
		cout << s1 << " ";
	}
	cout << endl;

	f1.close();
	return 0;
}
