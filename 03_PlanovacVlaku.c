#include <stdio.h>
#include <stdlib.h>

// potlaci warning o zastarale funkci (scanf apod)
//#pragma warning(disable:4996)

#define DELKAPOLE 30

// vypise cas ve formatu HH:MM, podle vstupu, 
// ktery je jen v minutach
void vypisCas(int casMinuty){
	printf("%02d:%02d ", casMinuty/60, casMinuty%60);
}

// resetuje hodnoty v poli na "-1"
// kde je -1, tam neni nic
void resetPole(int * pole, int velikost){
	for (int i = 0; i < velikost; ++i)
	{
		pole[i] = -1;
	}
}

// vypisuje odjezdy v poli, ale jenom takove
// ktere nejsou "-1"
void vypisPole(int * pole, int velikost){
	for(int i = 0; i < velikost; i++){
		if(pole[i] != -1){
			vypisCas(pole[i]);
		}
	}
}

void generujOdjezdy(int * pole, int velPole, int delkaOkruhu, 
					int nejdrivejsiOdjezd, int nejpozdejsiOdjezd){
	int aktualniOdjezd = nejdrivejsiOdjezd;
	for(int i=0; i<velPole; i++){
		pole[i] = aktualniOdjezd;
		aktualniOdjezd += delkaOkruhu;
		if(aktualniOdjezd > nejpozdejsiOdjezd) break;
	}
	
	return;

}

void inteligentniOdjezdy(int * o_nove, int velPole, int delkaOkruhu, 
						 int * o_ref, int navaznost, int nejpozdejsiOdjezd){
	
	int hodnota = o_ref[0];
	o_nove[0] = hodnota;
	int n = 1;

	/* prochazim referencni pole */
	for(int r = 1; o_ref[r] != -1; r++){
		hodnota = hodnota + delkaOkruhu;
		/* A - hodnota je mensi nez o_ref[r] a dalsi spoj se vejde */
		if(hodnota < o_ref[r] && (hodnota+delkaOkruhu <= o_ref[r]+navaznost)){
			
		}
		/* B - hodnota je mensi nez o_ref[r] a dalsi spoj se nevejde */

		/* C - hodnota je vetsi nez o_ref[r] a dalsi spoj je v toleranci */

		/* D - hodnota je vetsi nez o_ref[r] a dalsi spoj neni v toleranci */

	}
	
	return;
}

int main(int argc, char ** argv){

	// ulozim si delky okruhu v minutach
	int v1_okruh = 90;
	int v2_okruh = 170;
	int v3_okruh = 40;

	// kolik maximalne je mozne cekat na dalsi spoj, aby navazoval
	int navaznost = 10;

	int nejdrivejsiOdjezd = 5*60;   // 5:00 v minutach  
	int nejpozdejsiOdjezd = 23*60; // 23:00 v minutach

	int v1[DELKAPOLE]; resetPole(v1, DELKAPOLE); // pole pro odjezdy vlaku v1
	int v2[DELKAPOLE]; resetPole(v2, DELKAPOLE); // pole pro odjezdy vlaku v2
	int v3[DELKAPOLE]; resetPole(v3, DELKAPOLE); // pole pro odjezdy vlaku v3

	// generovani odjezdu pro nejdelsi okruh
	generujOdjezdy(v2, DELKAPOLE, v2_okruh, nejdrivejsiOdjezd, nejpozdejsiOdjezd);
	printf("Odjezdy vlaku 2 (Karlstejn):  ");
	vypisPole(v2, DELKAPOLE);

	inteligentniOdjezdy(v1, DELKAPOLE, v1_okruh, v2, navaznost, nejpozdejsiOdjezd);
	printf("Odjezdy vlaku 1 (Nizbor):     ");
	vypisPole(v1, DELKAPOLE);

	inteligentniOdjezdy(v3, DELKAPOLE, v3_okruh, v1, navaznost, nejpozdejsiOdjezd);
	printf("Odjezdy vlaku 3 (Cementarna): ");
	vypisPole(v3, DELKAPOLE);

	return 0;
}