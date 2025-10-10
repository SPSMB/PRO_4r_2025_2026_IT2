#include <iostream>

using namespace std;


int main( void ){

	string s0("Pocatecni retezec");
	string s1(s0);
	string s2(s0, 8, 3);
	string s5("Novy retezec je Tom", 10);
	string s6(100, '_');
	string s6b(10, 42);

	s1 = "Tom";
	s5 = s0.append(s1);
	s6 = s5.replace(17, 3, "Dan");

	float pi = 3.1415;
	string s7 = to_string(pi);


	cout << "s0: " << s0 << endl;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s5: " << s5 << endl;
	cout << "s6: " << s6 << endl;
	cout << "s6b: " << s6b << endl;
	cout << "Delka s0: " << s0.size() << endl;
	cout << "s0 na pozici 2: " << s0.at(2) << endl;
	cout << "s7: " << s7 << endl;
	


	return 0;
}