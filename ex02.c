#include <stdio.h>
#include <stdlib.h>

int main(){

    int base, expoente, conta = 1, i;

    printf("INFORME UM NUMERO PARA A BASE: ");
    scanf("%d", &base);
    printf("INFORME UM NUMERO PARA O EXPOENTE: ")/
    scanf("%d", &expoente);

    for(i = 0; i < expoente; i++){
        conta *= base;
    }

    printf("RESULTADO: %d", conta);

    return 0;
}
