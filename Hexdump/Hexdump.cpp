#include<stdio.h>
#include<string.h>

int main() {
	//Psaní do souboru
	FILE* soubor = fopen("hexdump.txt", "w");
	if (soubor == NULL) {
		printf("ERROR: Soubor hexdump.txt nelze otevrit pro zapis.\n");
		return 1;
	}
	char pismeno;
	fprintf(soubor, "Pismeno - ASCII - HEX\n");
	for (int i = 65; i < 91; i++) {
		pismeno = (char)i;
		fprintf(soubor, "%c - %3d\n", pismeno, i);
	}
	for (int j = 97; j < 122; j++) {
		pismeno = (char)j;
		fprintf(soubor, "%c - %3d\n", pismeno, j);
	}
	if (fclose(soubor) == EOF) {
		printf("ERROR: Soubor pokus.txt se nepodarilo otevrit.\n");
		return 1;
	}

	//return(0);

	//Čtení souboru
	FILE* soubor2 = fopen("hexdump.txt", "r");
	if (soubor2 == NULL) {
		printf("ERROR: Soubor hexdump.txt nelze otevrit pro cteni.\n");
		return 1;
	}

	char buffer[1024];
	int pocitadlo = 0;
	while (fgets(buffer, sizeof(buffer), soubor2) != NULL) {
		pocitadlo++;
		printf(" %2d. %s", pocitadlo, buffer);
	}
}