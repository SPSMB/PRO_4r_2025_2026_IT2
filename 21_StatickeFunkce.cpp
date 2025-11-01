#include <iostream>

using namespace std;

void mocnina1(){
	int lokalni = 2;
	lokalni = lokalni * 2;
	cout << "1: Lokalni: " << lokalni << endl;
}

void mocnina2(){
	static int lokalni = 2;
	lokalni = lokalni * 2;
	cout << "2: Lokalni: " << lokalni << endl;
}

int main(){

	for(int i = 0; i <= 7; i++){
		mocnina1();
		mocnina2();
	}


}