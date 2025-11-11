#include <iostream>
#include <iomanip>

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
	// vraci prenos - kolikrat pretekla
	int zvetsit(int x){
		c_hodnota += x;
		int prenos = c_hodnota / c_modul;
		c_hodnota = c_hodnota % c_modul;
		return prenos;
	}
	void zmensit(){
		c_hodnota = c_hodnota + c_modul;
		Citac::zmensit();
		c_hodnota = c_hodnota % c_modul;
	}
};

class Cas{
private:
	CitacMod c_hodiny;
	CitacMod c_minuty;
	CitacMod c_sekundy;
public:
	Cas(int hodiny, int minuty, int sekundy);
	void zvetsit(int sekundy);
	void vypis();
};

Cas::Cas(int hodiny, int minuty, int sekundy) 
 	: c_hodiny(hodiny,24), c_minuty(minuty,60), c_sekundy(sekundy,60){

}

void Cas::zvetsit(int sekundy){
	int prenos = c_sekundy.zvetsit(sekundy);
	prenos = c_minuty.zvetsit(prenos);
	c_hodiny.zvetsit(prenos);
}

void Cas::vypis(){
	cout << setw(2) << setfill('0') << c_hodiny.hodnota() 
		 << ":" << setw(2) << setfill('0') << c_minuty.hodnota() 
		 << ":" << setw(2) << setfill('0') << c_sekundy.hodnota() << endl;
}


int main(){

	Citac c1(10);
	c1.zvetsit();
	cout << "c1: " << c1.hodnota() << endl;

	CitacMod hodiny(23, 24);
	CitacMod minuty(59, 60);
	CitacMod sekundy(59, 60);
	CitacMod dnyVTydnu(0,6);
	cout << "dny: " << dnyVTydnu.hodnota() << endl;
	cout << "hodiny: " << hodiny.hodnota() << endl;
	cout << "minuty: " << minuty.hodnota() << endl;
	cout << "sekundy: " << sekundy.hodnota() << endl;

	// test tridy cas
	Cas c3(23,59,30);
	c3.vypis();
	c3.zvetsit(3700);
	c3.vypis();


	Citac x(10);
	CitacMod x1(10,20);
	CitacMod x2(20,30);

	x = x1;
	x1 = x;

	return 0;
}