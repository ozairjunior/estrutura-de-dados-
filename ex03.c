#include <stdio.h>

int main (){

int a = 0, b = 1, i, auxiliar = 1;

    for(i=0; i<15; i++){
        printf("%d\n", auxiliar);
        auxiliar = a +b;
        a = b;
        b = auxiliar;
    }
    return 0;
}
