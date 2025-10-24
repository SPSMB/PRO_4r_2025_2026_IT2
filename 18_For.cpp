#include <iostream>
#include <string>

using namespace std;

template <typename T>
T maximum(T * pole, int velikost){
	T max = -1000000;
	for(int i = 0; i < velikost; i++){
		if(pole[i] > max){
			max = pole[i];
		}
	}
	return max;
}

int main( void ){

	int pole[10] = {2,4,6,8,10,12,14,16,18,20};
	for(int &x : pole){
		x = x+1;
	}
	cout << "Maximum je " << maximum(pole, 10) << endl;

	for(int y : pole){
		cout << y << ","; 
	}
	cout << endl;

	string jmeno = "Tomas";
	string prijmeni = "Zimmerhakl";
	jmeno.append(" " + prijmeni);
	cout << "Spojeny retezec: " << jmeno << endl;

	return 0;
}