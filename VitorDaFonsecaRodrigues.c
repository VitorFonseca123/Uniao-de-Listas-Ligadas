#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ######### ESCREVA O NROUSP AQUI
char *nroUSP()
{
    return ("13838986");
}

// ######### ESCREVA SEU NOME AQUI
char *nome()
{
    return ("Vitor da Fonseca Rodrigues");
}

// elemento da lista
typedef struct estr
{
    int valor;
    struct estr *prox;
} NO;

// funcao principal
// NO *uniao(NO *p1, NO *p2);

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
/*NO *uniao(NO *p1, NO *p2)
{

    NO *resp = NULL;

    // seu codigo AQUI

    return resp;
}*/
void exibirLista(NO *inicio)
{
    NO *p = inicio;
    while (p)
    {
        printf("%d ", p->valor);
        p = p->prox;
    }
}

int contar(NO *inicio)
{
    int resp = 0;
    NO *p = inicio;

    while (p != NULL)
    {

        resp++;
        p = p->prox;
    }
    return (resp);
}

//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
void anexar(NO *inicio, int ch);
int main()
{

    NO *p1 = NULL;
    NO *p2 = NULL;

    // aqui vc pode incluir codigo para inserir elementos
    // de teste nas listas p1 e p2
    int Lista1[5] = {1, 2, 3, 4, 5};
    int Lista2[5] = {6, 7, 8, 9, 10};

    // printf("LISTA 2: %d\n", contar(&p2));
    for (int i = 0; i < 5; i++)
    {
        anexar(&p1, Lista1[i]);
    }

    exibirLista(&p1);
    // POR QUE RAIOS SE EU USO &P2 N FUNCIONA MAIS NADA
    printf("\nLISTA 1: %d\n", contar(&p1));
    printf("\nLISTA 1: %d\n", contar(&p2));

    // o EP sera testado com chamadas deste tipo
    // NO *teste = NULL;
    // teste = uniao(p1, p2);
}
void anexar(NO *inicio, int ch)
{
    NO *novo = (NO *)malloc(sizeof(NO));
    novo->valor = ch;
    novo->prox = NULL;
    NO *p = inicio;
    NO *ant = NULL;

    while (p)
    {
        ant = p;
        p = p->prox;
    }
    if (ant)
        ant->prox = novo;
    else
        inicio = novo;
}