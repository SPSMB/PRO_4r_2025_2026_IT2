#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592

// potlaci warning o zastarale funkci (scanf apod)
//#pragma warning(disable:4996)

float nactiVstup(void){

	float polomer;
	printf("Zadejte polomer naberacky: ");
	int kontrola = scanf("%f", &polomer);
	while(kontrola != 1){
		while(getchar()!='\n');
		printf("Toto neni platny vstup. Zadavejte znovu: ");
		kontrola = scanf("%f", &polomer);
	}
	return polomer;
}

int main(int argc, char ** argv){

	float polomer = nactiVstup();
	float objem = (2.0/3.0) * PI * pow(polomer, 3);

	printf("Objem naberacky je %.4f\n", objem);

	return 0;
}