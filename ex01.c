#include <stdio.h>
#include <stdlib.h>

int main () {

    int base, expoente, potencia;
    int numero;

	base = 3;
	expoente = 0;

	while (expoente <= 15) {
		if (expoente == 0) {
			potencia = 1;
		} else {
			if (expoente == 1) {
				potencia = base;
			} else {
				potencia *= base;
			}
		}

		printf("\t%d elevado a %d = %d\n", base, expoente, potencia);

		expoente += 1;

	}
    return 0;
}
