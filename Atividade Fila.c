#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

typedef struct elementos {
    char nome[50];
} t_elemento;

typedef struct no {
    t_elemento dado;
    struct no * prox;
} t_no;

typedef struct fila {
    t_no* inicio;
    int quant_element;
    t_no* final;
} t_fila;


t_fila * criaCabeca ()
{
    t_fila * fila = (t_fila*) malloc(sizeof(t_fila));

    if (fila) {
        fila->inicio = fila->final = NULL;
        fila->quant_element=0;
    }

    return fila;
}


t_no * criaNo() {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    if (no)
        no->prox = NULL;

    return no;
}


int isVazia (t_fila * fila)
{
    return (fila->quant_element == 0);
}


int inserir (t_fila *fila, t_elemento valor) {
    t_no *novo;
    novo = criaNo();
    if (novo == NULL)
        return 0; // Erro: memoria insuficiente
    novo->dado = valor;
    if (isVazia(fila))
        fila->inicio = novo;
    else
        (fila->final)->prox = novo;
    fila->final = novo;
    fila->quant_element++;
    return 1;
}


int remover (t_fila *fila)
{
    t_no *aux;
    t_elemento valor = { "" } ;
    if (isVazia(fila))
        return 0;
    valor = (fila->inicio)->dado;
    if (fila->inicio == fila->final)
        fila->final = NULL;
    aux = fila->inicio;
    fila->inicio = (fila->inicio)->prox;
    free(aux);
    fila->quant_element--;
    return 1;
}


void esvaziar(t_fila * fila1){
	
	int i;
	
	for(i = 0; i <= fila1->quant_element+1; i++){
		i = remover(fila1);
	}

}


void exibir(t_fila fila1){
	
	int i;
	
	for(i = 0; i < fila1.quant_element; i++){
		printf("%d Elemento: %s\n", i+1, (fila1.inicio)->dado.nome);
		fila1.inicio = (fila1.inicio)->prox;
	}

}


int menu(){
	
	int opcao;
	
	printf("Escolha uma das opcoes abaixo: \n");
	printf("1 - Criar a fila\n");
	printf("2 - Verificar se esta vazia\n");
	printf("3 - Inserir\n");
	printf("4 - Remover um elemento\n");
	printf("5 - Exibir fila\n");
	printf("6 - Esvaziar\n");
	printf(">> ");
	scanf("%d", &opcao);
	return opcao;
}


void cabecalho(){
	printf("ALUNO: OZAIR BARBOSA DE OLIVEIRA JUNIOR\n");
	printf("DISCIPLINA: ESTRUTURA DE DADOS I\n");
	printf("PROFESSOR: WALACE BONFIN\n");
}

int main(){
	
	int opcao, i;
	t_fila * fila1 = criaCabeca();
	t_elemento valorInserido;
	
    while(1){
    	cabecalho();
    	opcao = menu();
    	
    	switch(opcao){
    		case 1:
				printf("Criando nova fila...\n");
    			break;
    		case 2:
    			if(isVazia(fila1) == 1) printf("A fila esta vazia!!");
    			else printf("A fila nao esta vazia!!");
    			break;
    		case 3:
    			printf("Informe o valor para ser inserido na fila: ");
    			scanf("%s", &valorInserido.nome);
    			i = inserir(fila1, valorInserido);
    			if(i) printf("Valor inserido com sucesso!!\n");
    			else printf("Falha ao inserir!!\n");
    			break;
    		case 4:
    			i = remover(fila1);
    			if(i) printf("Removido com sucesso!!\n");
    			else printf("Falha ao remover!!\n");
    			break;
    		case 5:
    			exibir(*fila1);
    			break;
    		case 6:
    			printf("Esvaziando...");
    			esvaziar(fila1);
    			break;
		}
		system("pause");
		system("cls");
		
	}
}
