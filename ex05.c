#include <stdio.h>

int main(){

    int maior, menor, numero[5], i;

	int tam = (sizeof(numero)/sizeof(numero[0]));

	for(i=0;i<tam;i++){
		scanf("%d", &numero[i]);
	}

	for(i=0;i<tam;i++){
		if(i==0){
			maior = numero[i];
			menor = numero[i];
		}
		else{
			if(numero[i] > maior) maior = numero[i];
			if(numero[i] < menor) menor = numero[i];
		}
	}

	printf("Maior: %d\n", maior);
	printf("Menor: %d\n", menor);

    return 0;
}
