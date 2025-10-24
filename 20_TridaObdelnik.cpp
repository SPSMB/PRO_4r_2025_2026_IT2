#include <iostream>
#include <string>

using namespace std;


class Obdelnik{
private:
	int o_x, o_y;
	int o_sirka, o_vyska;
	int o_plocha, o_obvod;
public:
	Obdelnik(int x, int y, int sirka, int vyska);
	Obdelnik(int x, int y);
	Obdelnik();
	~Obdelnik();
	void vypocitejObvodObsah();
	void nastavRozmery(int x, int y, int sirka, int vyska);
	void normalizace(int alpha);
	void otoc(int x, int y, int alpha, int * resX, int * resY);
	void prohod(int & x, int & y);
	void otoc(int x, int y, char smer);
	bool jeUvnitr(int x, int y);
	void vypis(void);
};

Obdelnik::Obdelnik(int x, int y, int sirka, int vyska){
	nastavRozmery(x, y, sirka, vyska);
}

Obdelnik::Obdelnik(int x, int y){
	o_x = x;
	o_y = y;
	cout << "Sirka a vyska nebyla zadana, na nich nastavuji 0." << endl;
	o_sirka = 0; o_vyska = 0;
	o_plocha = 0; o_obvod = 0;
}

Obdelnik::Obdelnik(){
	cout << "Inicialiazace bez parametru! Davam vsude nulu." << endl;
	o_x = o_y = o_sirka = o_vyska = 0;
	o_plocha = 0; o_obvod = 0;
}

Obdelnik::~Obdelnik(){
	cout << "Vola se destruktor." << endl;
}

void Obdelnik::vypocitejObvodObsah(){
	o_plocha = o_sirka * o_vyska;
	o_obvod = 2 * o_sirka + 2 * o_vyska;
}

void Obdelnik::prohod(int & x, int & y){
	int tmp = x;
	x = y;
	y = tmp;
}

void Obdelnik::normalizace(int alpha){
	if(alpha == 90){
		o_x = o_x - o_vyska;
		prohod(o_sirka, o_vyska);
	} else if(alpha == -90){
		o_y = o_y - o_sirka;
		prohod(o_sirka, o_vyska);
	} else {
		// 180 stupnu
		o_x = o_x - o_sirka;
		o_y = o_y - o_vyska;
	}
}

void Obdelnik::otoc(int x, int y, int alpha, int * resX, int * resY);

void Obdelnik::nastavRozmery(int x, int y, int sirka, int vyska){
	o_x = x;
	o_y = y;
	o_sirka = sirka;
	o_vyska = vyska;
	vypocitejObvodObsah();
}

void Obdelnik::vypis(void){
	cout << "Souradnice rohu: [" << o_x << "," << o_y << "]" << endl;
	cout << "Sirka: " << o_sirka << endl;
	cout << "Vyska: " << o_vyska << endl;
	cout << "Plocha: " << o_plocha << endl;
	cout << "Obvod: " << o_obvod << endl;
}

int main( void ){

	Obdelnik skola(10,15,300,500);
	skola.vypis();
	//skola.nastavRozmery(20,35, 1000,2000);
	//skola.vypis();

	//Obdelnik magistrat(250,1400,50,80);
	//magistrat.vypis();

	//Obdelnik divadlo;
	//divadlo.vypis();

	//Obdelnik banka(11,22);
	//banka.vypis();

	skola.normalizace(90);
	skola.vypis();

	return 0;
}