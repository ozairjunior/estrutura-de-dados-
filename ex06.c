#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    float largura;
    float comprimento;
    float area;
}REGISTRO;

int main(){

    REGISTRO comodo[13];
    char resposta[3];
    int i = 0, j;
    float area_total = 0;

    while(1){

        printf("INFORME O NOME DO COMODO: ");
        scanf("%s", &comodo[i].nome);

        printf("\nINFOMRE A LARGURA DO COMODO: ");
        scanf("%f", &comodo[i].largura);

        printf("\nINFORME O COMPRIMENTO DO COMODO: ");
        scanf("%f", &comodo[i].comprimento);

        comodo[i].area = comodo[i].largura * comodo[i].comprimento;
        printf("AREA: %.2f\n", comodo[i].area);

        printf("\nQUER CONTINUAR? [SIM/NAO]");
        scanf("%s", resposta);
        if(strncmp(resposta, "NAO", 3) == 0) break;

        i++;
    }

    fflush(stdin);

    for(j = 0; j <= i; j++){

        printf("\nCOMODO: %s \nLARGURA: %.2f \nCOMPRIMENTO: %.2f\n", comodo[j].nome, comodo[j].largura, comodo[j].comprimento);
        area_total += (comodo[j].largura * comodo[j].comprimento);
    }

    printf("\nAREA TOTAL: %.2f", area_total);

    return 0;
}
