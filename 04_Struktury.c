#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct clovek {
	char jmeno[30];
	char prijmeni[30];
} Clovek;

int main(int argc, char ** argv){

	Clovek Tomas;
	strcpy(Tomas.jmeno, "Tom");

	Clovek * u_Tomas = & Tomas;
	printf("%s\n", u_Tomas->jmeno);

	return 0;
}