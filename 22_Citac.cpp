#include <iostream>

using namespace std;

class Citac{
protected:
	int c_hodnota;
	int c_pocHodnota;
public:
	void zvetsit(){	c_hodnota++; }
	void zmensit(){	c_hodnota--; }
	void nastavit(){ c_hodnota = c_pocHodnota; }
	int hodnota(){ return c_hodnota; }
	Citac(int pocHodnota){
		c_pocHodnota =pocHodnota;
		nastavit();
	}
};

class CitacMod : public Citac{
private:
	int c_modul;
public:
	CitacMod(int pocHodnota, int modul) : Citac(pocHodnota%modul){
		c_modul = modul;
	}
	void zvetsit(){
		Citac::zvetsit();
		c_hodnota = c_hodnota % c_modul;
	}
	void zmensit(){
		c_hodnota = c_hodnota + c_modul;
		Citac::zmensit();
		c_hodnota = c_hodnota % c_modul;
	}
};

int main(){

	Citac c1(10);
	c1.zvetsit();
	cout << "c1: " << c1.hodnota() << endl;

	CitacMod c2(9, 10);
	cout << "c2: " << c2.hodnota() << endl;
	c2.zvetsit();
	cout << "c2: " << c2.hodnota() << endl;
	c2.zmensit();
	cout << "c2: " << c2.hodnota() << endl;

	return 0;
}