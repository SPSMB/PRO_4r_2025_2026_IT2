#include <iostream>
#include <iomanip>

using namespace std;

int main( void ){
	cout << "   ";
	for (int i = 1; i <= 10; ++i)
	{
		cout << setw(4)<< i;
	}
	cout << endl;
	for(int i = 1; i <= 3+10*4; i++){ 
		cout << "_"; 
	}
	cout << endl;
	for (int i = 10; i <= 20; ++i)
	{
		cout << i << ":";
		for (int j = 1; j <= 10; ++j)
		{
			cout << setw(4) << i*j;
		}
		cout << endl;
	}

	return 0;
}