#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *anterior, *proximo;

} no;

struct no *topo, *auxiliar;

void enterdata()
{

    printf("Insira um valor: ");
    scanf("%d", &topo-> valor);
}

void Push()
{

    no *novo = malloc(sizeof(no));

    if (novo == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }

    novo -> proximo = NULL;

    if(topo == NULL)
    {
        novo -> anterior = NULL;
        topo = novo;
        auxiliar = novo;
        enterdata();
    }
    else
    {
        novo -> anterior = auxiliar;
        novo -> proximo = NULL;
        topo = novo;
        auxiliar -> proximo = novo;
        auxiliar = novo;
        enterdata();
    }
}

void Pop()
{

    if(topo == NULL)
    {
        printf("Lista Vazia....\n");
        return;
    }
        auxiliar = topo;
        if(topo -> anterior == NULL && topo -> proximo == NULL)
        {
            free(auxiliar);
            auxiliar = NULL;
            topo = NULL;
            printf("Removendo o ultimo elemento da pilha...\n");
            system("pause");
        }else
            {
                auxiliar = topo;
                topo = topo -> anterior;
                topo -> proximo = NULL;
                free(auxiliar);
                printf("Removido com sucesso elemento da pilha!!");
                system("pause");
            }
}

void Top(){

    if(topo ==
        NULL){
        printf("Lista Vazia...\n");
        return;
    }

    printf("Elemento no topo: %d\n", topo ->valor);
    system("pause");
    }


void Exibir()
{

    auxiliar = topo;

    // Vai voltar até apontar pro primeiro nó.
    while(auxiliar->anterior != NULL)
    {
        auxiliar = auxiliar -> anterior;
    }

    while (auxiliar != NULL)
    {
        printf("%d\n", auxiliar->valor);
        auxiliar = auxiliar->proximo;
    }
}


int main()
{
    topo = NULL;
    auxiliar = NULL;

    int opcao;

    do
    {
        printf("============= PILHA =============\n");
        printf("[1] INSERIR\n");
        printf("[2] REMOVER\n");
        printf("[3] CONSULTAR\n");
        printf("[4] EXIBIR\n");
        printf("[5] SAIR\n");
        printf("Escolha uma opcao: ");
        scanf("%d",&opcao);
        printf("\n\n");

        switch(opcao)
        {
        case 1:
            Push();
            system("cls");
            break;
        case 2:
            Pop();
            system("cls");
            break;
        case 3:
            Top();
            break;
        case 4:
            Exibir();
            break;
        case 5:
            exit(0);
        }
    }
    while(opcao != 5);
}





















