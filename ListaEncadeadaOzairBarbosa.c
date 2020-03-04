#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

VER COM ANDERSON SE ESTA CERTO OS COMENTARIOS DE CADA LINHA

*/
typedef struct elementos {
    char nome[50];//QUANTIDADE DE NOMES 0 ATE 49
} t_elemento;

typedef struct no {
    t_elemento dado;//FAZENDO A LIGACAO DE T_ELEMENTO COM T_NO
    struct no  * prox;//FAZENDO UM PONTEIRO PARA O PROXIMO ELEMENTO NO NÓ
} t_no;

typedef t_no* t_lista;//FAZENDO UM PONTEIRO PARA T_NO


t_no * criaNo();

t_no * getNo(t_lista lista, int pos) {
    int n = 0;

    if (pos < 0)
        return 0;

    while (lista != NULL) {
        if (n==pos)
            return lista;
        lista = lista->prox;//AQUI VAI ESTA ATRIBUINDO UM NOVO NÓ COM NOVO VALOR
        n++;
    }

    return 0;
}

int getTamanho(t_lista lista) {
    int n = 0;

    while (lista != NULL) {
        lista = lista->prox;//VAI FAZENDO AS ATRIBUIÇÕES
        n++;//DIZ O TAMANHO DA LISTA
    }
    return n;
}

int inserir(t_lista* lista, int pos, t_elemento dado) {

    t_no * p, * novo;

    if (pos == 0) {
        novo = criaNo();
        if (novo == NULL)
            return 0;
        novo->dado = dado;//COLOCA DADO NO LUGAR DELA
        novo->prox = * lista;//DEPOIS DE INSERIR O DADO VAI PRO PROXIMO DA LISTA
        *lista = novo;//LISTA APONTA O NOVO DADO PARA O PROXIMO NO
        return 1;
    }

    p = getNo(* lista, pos-1);//P RECEBE UMA NOVA ATRIBUIÇÃO COM DADO E A POSIÇÃO

    if (p == NULL)
         return 0;

    novo = criaNo();

    if (novo == NULL)
        return 0;

    novo->dado = dado;//SALVA DADO EM DADO
    novo->prox = p->prox;//APONTA PARA O PROXIMO NO
    p->prox = novo;//

    return 1;
}

void Lista(t_lista lista){

    int c = 1;

    while(lista->prox != NULL){
        printf("\nNo[%d]: ", c);
        printf("\n\tDado: %s", lista->dado.nome);
        lista = lista->prox;
        c++;
    }

    putchar('\n');

    system("pause");
}

t_no * criaNo() {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    if (no)
        no->prox = NULL;

    return no;
}

int isVazia(t_lista lista) {
    return (lista == NULL);
}

int remover(t_lista * lista, int pos) {
    t_no *anterior, *p;
    if (isVazia(*lista)) return 0;
    if (pos < 0) return 0;

    if (pos == 0) {
        p = *lista;
        *lista = p->prox;
    } else {
        anterior = getNo(*lista, pos-1);
        if (anterior == NULL)
            return 0;
        p = anterior->prox;
        if (p == NULL)
            return 0;
        anterior->prox = p->prox;
    }
    free(p);
    return 1;
}

int compara(t_elemento dado1, t_elemento dado2) {
    return strcmp(dado1.nome, dado2.nome);
}

int getPosicao(t_lista lista, t_elemento dado) {
    int n = 0;

    while (lista != NULL) {
        if (compara(lista->dado, dado)== 0)
            return n;
        lista = lista->prox;
        n++;
    }

    return -1;
}

t_elemento * getElemento(t_lista lista, int pos){

    t_no * no = getNo(lista, pos);
    if (no != NULL)
        return &(no->dado);
    else
        return NULL;
}

int menu(){

    int escolha;

    printf("\t\t\tALUNO: OZAIR BARBOSA DE OLIVEIRA JUNIOR\n");
    printf("\t\t\tDISCIPLINA: ESTRUTURA DE DADOS\n");
    printf("\t\t\tPROFESSOR: WALACE BONFIM\n");
    putchar('\n');
    printf("\t\t\tEDITOR DE LISTAS\n");
    printf("\t1 - EXIBIR LISTA\n");
    printf("\t2 - INSERIR ORDENADAMENTE\n");
    printf("\t3 - REMOVER PELO DADO\n");
    printf("\t4 - REMOVER PELA POSICAO\n");
    printf("\t5 - REMOVER UM INTERVALO DE NOS\n");
    printf("\t6 - EXIBIR ELEMENTO\n");
    printf("\t7 - EXIBIR POSICAO DO ELEMENTO (PROCURAR)\n");
    printf("\t8 - ESVAZIR\n");
    printf("\t0 - SAIR\n");
    putchar('\n');
    printf("\tDIGITE SUA OPCAO: ");
    scanf("%d", &escolha);

    return escolha;
}

int main(){

    t_lista L = criaNo();
    t_elemento info;
    t_elemento * info2;
    int lugar, inicio, fim, c;

    while(1){

        int escolha = menu();

        switch(escolha){

        case 0:
            exit(0);
            break;

        case 1:
            Lista(L);
            system("cls");
            break;

        case 2:
            printf("\n\t\t\t DIGA UM NOME QUE DESEJA COLOCAR NA SUA LISTA: ");
            scanf("%s", info.nome);
            lugar = getTamanho(L);
            inserir(&L, lugar-1, info);
            system("cls");
            break;

        case 3:
            printf("\n\t\t\tDIGA O DADO(NOME) QUE DESEJA APAGAR DA SUA LISTA: ");
            scanf("%s", info.nome);
            lugar = getPosicao(L, info);
            remover(&L, lugar);
            system("cls");
            break;

        case 4:
            printf("\n\t\t\tDIGA A POSICAO DO NOME QUE DESEJA APAGAR DA SUA LISTA: ");
            scanf("%d", &lugar);
            remover(&L, lugar-1);
            system("cls");
            break;

        case 5:
            printf("\n\t\t\tDIGA A POSICAO INICIAL QUE DESEJA APAGAR: ");
            scanf("%d", &inicio);
            printf("\n\t\t\tDIGA ATE QUE POSICAO DESEJA APAGAR: ");
            scanf("%d", &fim);

            for(c = fim; c >= inicio; c--){
                remover(&L, c-1);
            }
            system("cls");
            break;

        case 6:
            printf("\n\t\t\tDIGA QUAL A POSICAO DO DADO(NOME) DESEJA VER: ");
            scanf("%d", &lugar);
            info2 = getElemento(L, lugar-1);
            printf("%s\n", info2->nome);
            system("pause");
            system("cls");
            break;

        case 7:
            printf("\n\t\t\tDIGA QUAL O DADO(NOME) PARA VER SUA POSICAO: ");
            scanf("%s", info.nome);
            lugar = getPosicao(L, info);
            printf("POSICAO: %d\n", lugar+1);
            system("pause");
            system("cls");
            break;

        case 8:
            free(L);
            L = criaNo();
            system("pause");
            system("cls");
            break;
        default:
            printf("OPCAO INVALIDA!\n");
            break;

        }
    }

}
