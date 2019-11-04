#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Tipo base dos elementos da lista
typedef struct elementos {
    char nome[50];
    int num;
} t_elemento;

// Estrutura da pilha
typedef struct pilha {
    t_elemento vetor[MAX];
    int topo;
} t_pilha;


t_pilha criar() {
    t_pilha pilha;

    pilha.topo = -1;

    return pilha;
}


int isVazia(t_pilha * pilha) {
    return (pilha->topo == -1);
}


int isCheia(t_pilha * pilha) {
    return (pilha->topo == MAX-1);
}


t_elemento getElementoTopo(t_pilha * pilha)
{
    t_elemento vazio = { "" } ;

    if (isVazia(pilha))
        return vazio; // erro
    else
        return pilha->vetor[pilha->topo];
}


t_elemento pop(t_pilha * pilha)
{
    t_elemento vazio = { "" };

    if (isVazia(pilha))
        return vazio; // erro
    else
        return pilha->vetor[pilha->topo--];
}


int push(t_pilha *pilha, t_elemento valor)
{
    if (isCheia(pilha))
        return 0; // erro

    pilha->vetor[++pilha->topo] = valor;

    return 1; // sucesso
}


int menu(){
	int opcao;
	printf("Escolha uma opcao abaixo: \n");
	printf("\t1 - Criar uma pilha\n");
	printf("\t2 - Testar se a pilha esta vazia\n");
	printf("\t3 - Testar se a pilha esta cheia\n");
	printf("\t4 - Obter o elemento do topo (sem eliminar)\n");
	printf("\t5 - Empinar um novo elemento (push)\n");
	printf("\t6 - Desempilhar o elemento do topo (pop)\n");
	printf("\t7 - Exibir os elementos da pilha\n");
	printf("\t>> ");
	scanf("%d", &opcao);
	return opcao;
}


void exibir(t_pilha * pilha1){

	int i;

	for(i = 0; i <= pilha1->topo; i++) printf("\n%d elemento:\n\tNome: %s \n\tNumero: %d\n", i+1, pilha1->vetor[i].nome, pilha1->vetor[i].num);
}


void cabecalho(){
	printf("ALUNO: OZAIR BARBOSA DE OLIVEIRA JUNIOR\n");
	printf("DISPLINA: ESTRUTURA DE DADOS\n");
	printf("PROFESSOR: WALACE BONFIM\n\n");
}

int main(){

	int opcao, retorno;
	t_pilha pilha1 = criar();
	t_elemento elementoTopo;

	while(1){
		cabecalho();
		opcao = menu();
		switch(opcao){
			case 1:
				break;
			case 2:
				if(isVazia(&pilha1) == 1) printf("\tA pilha esta vazia!!\n");
				else printf("\tA pilha nao esta vazia!!\n");
				break;
			case 3:
				if(isCheia(&pilha1) == 1) printf("\t\tA pilha esta cheia!!\n");
				else printf("\tA pilha nao esta cheia!!\n");
				break;
			case 4:
				elementoTopo = getElementoTopo(&pilha1);
				printf("\tElemento do topo: %s e %d\n", elementoTopo.nome, elementoTopo.num);
				break;
			case 5:
				printf("Informe o novo elemento: \n");
				printf("Nome: ");
				scanf("%s", &elementoTopo.nome);
				printf("Valor: ");
				scanf("%d", &elementoTopo.num);
				retorno = push(&pilha1, elementoTopo);
				if(retorno == 1) printf("Elemento inserido com sucesso!!\n");
				else printf("Pilha cheia!!");
				break;
			case 6:
				elementoTopo = pop(&pilha1);
				printf("Valor removido: \n");
				printf("Nome: %s // Numero: %d\n", elementoTopo.nome, elementoTopo.num);
				break;
			case 7:
				exibir(&pilha1);
				break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}
