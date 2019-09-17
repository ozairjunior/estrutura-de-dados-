#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ALN 60
#define NUM_DISC 3

typedef struct{
    char disciplina[15];
    float nota;

}lista_2;


typedef struct{
    int matricula;
    lista_2 disciplinas[NUM_DISC];

}lista_1;


typedef struct{
    lista_1 alunos[NUM_ALN];
    int n;

}lista_0;

// EXIBE OS DADOS CADASTRADOS
void exibirDados(lista_0 * estudantes){

    int id, i, cont;

    printf("\n\tDiga sua matricula: ");
    scanf("%d", &id);

    putchar('\n');

    for(i = 0; i < estudantes->n; i++){
        if(id == estudantes->alunos[i].matricula){
            for(cont = 0; cont < NUM_DISC; cont++){
                printf("\t\tDisciplina %d -> %s\n", cont, estudantes->alunos[i].disciplinas[cont].disciplina);
                printf("\t\tNota -> %.2f\n\n", estudantes->alunos[i].disciplinas[cont].nota);
            }
        }
        else{
            printf("\t\tNao encntramos essa matricula no sistema!!\n");
        }
    }
}

// REGISTRA OS ALUNOS
void registrando(lista_0 * estudantes){

    int i;

    printf("\n\tDiga sua matricula: ");
    scanf("%d", &estudantes->alunos[estudantes->n].matricula);

    putchar('\n');

    for(i = 0; i < NUM_DISC; i++){

        printf("\t\tDisciplina %d -> ", i);
        scanf("%s", estudantes->alunos[estudantes->n].disciplinas[i].disciplina);

        printf("\t\tNota -> ");
        scanf("%f", &estudantes->alunos[estudantes->n].disciplinas[i].nota);

        putchar('\n');
    }

    estudantes->n++;

}

// CRIA A LISTA PRINCIPAL
lista_0 * criarLista(){

    lista_0 * lista;

    lista = (lista_0 *) malloc(sizeof(lista_0));

    lista->n = 0;

    return lista;
}

// EXIBE AS OPCOES DE ENTRADA
int menu(){

    int opcao = 0;

    printf("\t\tHistorico Escolar\n\n");

    printf("\t1 - Inserir Matricula, Disciplinas e Notas\n");
    printf("\t2 - Exibir Historico\n");
    printf("\t0 - Sair\n\n");

    printf("\tDigite uma opcao: ");
    scanf("%d", &opcao);

    return opcao;
}


void cabecalho(){
    printf("ALUNO: Ozair Barbosa de Oliveira Junior\n");
    printf("DISCIPLINA: Estrutura de Dados I\n");
    printf("PROFESSOR: Walace Bonfim\n\n");
}


int main()
{
    int opcao;
    lista_0 * estudantes;

    estudantes = criarLista();

    while(1){

        cabecalho();
        opcao = menu();

        switch(opcao){
        case 0:
            exit(0);
            free(estudantes);
        case 1:
            registrando(estudantes);
            break;
        case 2:
            exibirDados(estudantes);
            system("pause");
            break;
        }

        system("cls");
    }

    return 0;
}
