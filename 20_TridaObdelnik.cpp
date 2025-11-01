#include <iostream>
#include <string>
#include <math.h>

using namespace std;


class Obdelnik{
private:
	int o_x, o_y;
	int o_sirka, o_vyska;
	int o_plocha, o_obvod;
public:
	static int o_pocetObdelniku;
	Obdelnik(int x, int y, int sirka, int vyska);
	Obdelnik(int x, int y);
	Obdelnik();
	~Obdelnik();
	void vypocitejObvodObsah();
	void nastavRozmery(int x, int y, int sirka, int vyska);
	void normalizace(int alpha);
	void otocPodlePocatku(int x, int y, int alpha, int * resX, int * resY);
	void prohod(int & x, int & y);
	void otocPodleStredu(int x, int y, int alpha);
	bool jeUvnitr(int x, int y);
	void vypis(void) const;
	static int kolik();
};

int Obdelnik::o_pocetObdelniku = 0; // incicializace staticke promenne

Obdelnik::Obdelnik(int x, int y, int sirka, int vyska){
	nastavRozmery(x, y, sirka, vyska);
	o_pocetObdelniku++;
}

Obdelnik::Obdelnik(int x, int y){
	o_x = x;
	o_y = y;
	cout << "Sirka a vyska nebyla zadana, na nich nastavuji 0." << endl;
	o_sirka = 0; o_vyska = 0;
	o_plocha = 0; o_obvod = 0;
	o_pocetObdelniku++;
}

Obdelnik::Obdelnik(){
	cout << "Inicialiazace bez parametru! Davam vsude nulu." << endl;
	o_x = o_y = o_sirka = o_vyska = 0;
	o_plocha = 0; o_obvod = 0;
	o_pocetObdelniku++;
}

Obdelnik::~Obdelnik(){
	cout << "Vola se destruktor." << endl;
	o_pocetObdelniku--;
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

void Obdelnik::otocPodleStredu(int sx, int sy, int alpha){

	// 1) Transformace
	int x_AT = o_x - sx;
	int y_AT = o_y - sy;

	// 2) Rotace
	int x_ATR; int y_ATR;
	otocPodlePocatku(x_AT, y_AT, alpha, &x_ATR, &y_ATR);

	// 3) Zpetna transformace
	int x_AR, y_AR;
	x_AR = x_ATR + sx;
	y_AR = y_ATR + sy;

	// 4) Normalizace
	o_x = x_AR;
	o_y = y_AR;
	normalizace(alpha);
}


void Obdelnik::otocPodlePocatku(int x, int y, int alpha, int * resX, int * resY){
	float alphaRAD = alpha * (3.1415/180);
	*resX = round(x * cos(alphaRAD) - y * sin(alphaRAD));
	*resY = round(x * sin(alphaRAD) + y * cos(alphaRAD));
}

void Obdelnik::nastavRozmery(int x, int y, int sirka, int vyska){
	o_x = x;
	o_y = y;
	o_sirka = sirka;
	o_vyska = vyska;
	vypocitejObvodObsah();
}
bool Obdelnik::jeUvnitr(int x, int y){
	return (x >= o_x && x <= o_x + o_sirka && y >= o_y && y <= o_y + o_vyska );
}
void Obdelnik::vypis(void) const{
	cout << "Souradnice rohu: [" << o_x << "," << o_y << "]" << endl;
	cout << "Sirka: " << o_sirka << endl;
	cout << "Vyska: " << o_vyska << endl;
	cout << "Plocha: " << o_plocha << endl;
	cout << "Obvod: " << o_obvod << endl;
	cout << "Pocet obdelniku: " << o_pocetObdelniku << endl;
}

int Obdelnik::kolik(){
	return o_pocetObdelniku;
}

int main( void ){

	Obdelnik skola(2,3,4,2);
	skola.vypis();
	//skola.nastavRozmery(20,35, 1000,2000);
	//skola.vypis();

	//Obdelnik magistrat(250,1400,50,80);
	//magistrat.vypis();

	//Obdelnik divadlo;
	//divadlo.vypis();

	//Obdelnik banka(11,22);
	//banka.vypis();

	//skola.normalizace(90);
	//skola.otocPodleStredu(4,6,-90);
	skola.vypis();

	Obdelnik * u_hriste = new Obdelnik(-5,-4,8,2);
	cout << "HRISTE ----------------------" << endl;
	u_hriste->vypis();
	u_hriste->otocPodleStredu(5,-3,90);
	u_hriste->vypis();
	delete u_hriste;
	 // volani staticke metody
	cout << "Pocet obdelniku: " << Obdelnik::kolik() << endl;
	cout << "To je muj vypis - radek 145." << endl;
	if (skola.jeUvnitr(-1,-1))
	{
		cout <<"je uvnitr"<< endl;
	}else{
		cout << "neni uvnitr" <<endl;
	}

	return 0;
}