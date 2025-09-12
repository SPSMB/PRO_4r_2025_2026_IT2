#include <stdio.h>
#include <stdlib.h>

// potlaci warning o zastarale funkci (scanf apod)
//#pragma warning(disable:4996)

#define DELKAPOLE 30

// vypise cas ve formatu HH:MM, podle vstupu, 
// ktery je jen v minutach
void vypisCas(int casMinuty){
	printf();
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
			printf("%d ",pole[i]);
		}
	}
}

void generujOdjezdy(int * pole, int velPole, int delkaOkruhu, 
					int nejdrivejsiOdjezd, int nejpozdejsiOdjezd){
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
	v2[0] = 100;
	printf("Odjezdy vlaku 2 (Karlstejn): ");
	vypisPole(v2, DELKAPOLE);

	return 0;
}