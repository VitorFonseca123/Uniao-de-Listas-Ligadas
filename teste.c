#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// elemento da lista
typedef struct estr
{
    int valor;
    struct estr *prox;
} NO;
typedef struct
{
    NO *inicio;
} LISTA;

void inicializar(LISTA *l)
{
    l->inicio = NULL;
}
void exibirLista(LISTA *l)
{
    NO *p = l->inicio;
    while (p)
    {
        printf("%d ", p->valor);
        p = p->prox;
    }
}

int contar(LISTA *l)
{
    int resp = 0;
    NO *p = l->inicio;

    while (p != NULL)
    {

        resp++;
        p = p->prox;
    }
    return (resp);
}

int main()
{
    int vetor1[] = {1, 2, 3, 4, 5};
    int vetor2[] = {6};

    LISTA p1;
    LISTA p2;
    inicializar(&p1);
    inicializar(&p2);
    printf("ZERADO\n");
    printf("%d\n", contar(&p1));
    printf("%d\n", contar(&p2));
    printf("ANEXAR\n");
    int i;
    for (i = 0; i<5; i++)
    {
        anexar(&p1, vetor1[i]);
    }
    for (i = 0; i<1; i++)
    {
        anexar(&p2, vetor2[i]);
    }
    printf("%d\n", contar(&p1));
    exibirLista(&p1);
    printf("\n%d\n", contar(&p2));
    exibirLista(&p2);
}
void anexar(LISTA *l, int ch)
{
    NO *novo = (NO *)malloc(sizeof(NO));
    novo->valor = ch;
    novo->prox = NULL;
    NO *p = l->inicio;
    NO *ant = NULL;

    while (p)
    {
        ant = p;
        p = p->prox;
    }
    if (ant)
        ant->prox = novo;
    else
        l->inicio = novo;
}