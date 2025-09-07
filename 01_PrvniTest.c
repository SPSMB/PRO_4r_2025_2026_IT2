#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

int main(int argc, char ** argv){

	// testujeme, co se vypise, po volani funkce memset
	// Vystup neni definovan, protoze na konec retezce jsme nedoplnili ukoncovaci znak '\0' 
	
	char str[30] = "Testovaci data 12345678";
	char s[30];
	memset(s, '*', sizeof(s) - 1);
	printf("%s<\n", s);

	return 0;
}