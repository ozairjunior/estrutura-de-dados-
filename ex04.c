#include <stdio.h>

int main () {

    int	quadro;

    long long int trigo = 1, trigo_total = 1;

    for(quadro=0;quadro<64;quadro++){
		trigo = trigo * 2;
		trigo_total =+ trigo;
	}

	printf("No tabuleiro tem %.0f graos de trigo.\n", trigo_total);

}
