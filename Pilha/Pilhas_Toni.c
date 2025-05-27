#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    int ra;
    char nome[20];
    struct no* anterior, *proximo;
} no;

struct no* topo, *auxiliar;

void Enterdata()
{

    printf("Insira o RA: ");
    scanf("%d", &topo->ra);

    printf("Insira o Nome: ");
    scanf("%s", topo->nome);
}

void push()
{
    if(topo == NULL)
    {
        topo = (no*)malloc(sizeof(no));
        topo -> anterior = NULL;
        topo -> proximo = NULL;
        auxiliar = topo;
        Enterdata();
    }
    else
    {
        topo = (no*)malloc(sizeof(no));
        auxiliar -> proximo = topo;
        topo -> proximo = NULL;
        topo -> anterior = auxiliar;
        auxiliar = topo;
        Enterdata();
    }
}

void pop()
{
    int ra_busca;
    printf("Insira o RA que deseja remover: ");
    scanf("%d", &ra_busca);

    if (topo == NULL)
    {
        printf("Lista Vazia...\n");
        return;
    }
    else
    {
        auxiliar = topo;
        if(topo -> proximo == NULL && topo->anterior == NULL)
        {
            free(auxiliar);
            auxiliar = NULL;
            topo = NULL;
            printf("\n Removendo o ultimo elemento da pilha..");
            system("pause");
        }
        else
        {
            auxiliar = topo;
            topo = topo -> anterior;
            topo -> proximo = NULL;
            free(auxiliar);
            printf("Removido com sucesso elemento da pilha..\n");
            system("pause");


        }
    }


}



void top()
{
    if (topo == NULL)
    {
        printf("Lista Vazia...\n");
        return;
    }

    printf("Topo: RA: %d, Nome: %s\n", topo->ra, topo->nome);
}


int main()
{
    int opcao;

    do
    {
        printf("============= PILHA =============\n");
        printf("[1] INSERIR\n");
        printf("[2] REMOVER\n");
        printf("[3] CONSULTAR\n");
        printf("Escolha uma opcao: ");
        scanf("%d",&opcao);
        printf("\n\n");


        switch(opcao)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            top();
            break;
        case 5:
            exit(0);
        }
    }
    while(opcao != 5);
}


