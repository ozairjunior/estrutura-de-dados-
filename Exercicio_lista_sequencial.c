#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ALN 60
#define NUM_DISC 3

typedef struct lista2
{
    char disciplina[15];
    float nota;

}lista_2;

typedef struct lista1
{
    int matricula;
    lista_2 disciplinas[NUM_DISC];

}lista_1;

typedef struct lista0
{
    lista_1 alunos[NUM_ALN];
    int n;

}lista_0;

int exibirDados(lista_0 * estudantes);
void registrando(lista_0 * estudantes);
lista_0 * criarLista();
int menu();

int main()
{
    int opcao;
    lista_0 * estudantes;
    estudantes = criarLista();

    while(1){
        printf("ALUNO: Ozair Barbosa de Oliveira Junior\n");
        printf("DISCIPLINA: Estrutura de Dados I\n");
        printf("PROFESSOR: Walace Bonfim\n\n");

        opcao = menu();
        switch(opcao){
            case 0:
                free(estudantes);
                return 0;
            case 1:
                registrando(estudantes);
                break;
            case 2:
                exibirDados(estudantes);
                break;
        }
        system("cls");
    }
    return 0;
}
// EXIBE OS DADOS CADASTRADOS
int exibirDados(lista_0 * estudantes)
{
    int id, i, cont;
    printf("\n\tDiga sua matricula: ");
    scanf("%d", &id);

    for(i = 0; i < estudantes->n; i++){
        if(id == estudantes->alunos[i].matricula){
            for(cont = 0; cont < NUM_DISC; cont++){
                printf("\n\t\tDisciplina %d -> %s\n", cont, estudantes->alunos[i].disciplinas[cont].disciplina);
                printf("\t\tNota -> %.2f\n\n", estudantes->alunos[i].disciplinas[cont].nota);
            }
            system("pause");
            return 0;
        }
    }

    printf("\t\tNao encontramos essa matricula no sistema!!\n");

    system("pause");

    return 0;
}
// REGISTRA OS ALUNOS
void registrando(lista_0 * estudantes)
{
    int i;

    printf("\n\tDiga sua matricula: ");
    scanf("%d", &estudantes->alunos[estudantes->n].matricula);

    for(i = 0; i < NUM_DISC; i++){
        printf("\n\t\tDisciplina %d -> ", i);
        scanf("%s", estudantes->alunos[estudantes->n].disciplinas[i].disciplina);
        printf("\t\tNota -> ");
        scanf("%f", &estudantes->alunos[estudantes->n].disciplinas[i].nota);
        putchar('\n');
    }
    estudantes->n++;
}
// CRIA A LISTA PRINCIPAL
lista_0 * criarLista()
{
    lista_0 * lista;
    lista = (lista_0 *) malloc(sizeof(lista_0));
    lista->n = 0;

    return lista;
}
// EXIBE AS OPCOES DE ENTRADA
int menu()
{
    int opcao = 0;

    printf("\t\tHistorico Escolar\n\n");
    printf("\t[1] - Inserir Matricula, Disciplinas e Notas\n");
    printf("\t[2] - Exibir Historico\n");
    printf("\t[0] - Sair\n\n");

    printf("\tDigite uma opcao: ");
    scanf("%d", &opcao);

    return opcao;
}
