#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct NO
{
    char nome[15];
    int quant;
    bool vida;
    struct NO *esq;
    struct NO *dir;
} no;

void adicionar(no **n, const char *nm)
{
    if (*n)
    {
        no *n0 = *n;
        int i = strcmp(n0->nome, nm);
        if (i > 0)
            adicionar(&n0->esq, nm);
        else if (i < 0)
            adicionar(&n0->dir, nm);
        else
            n0->quant++;
    }
    else
    {
        no *novo = (no *)malloc(sizeof(no));
        novo->esq = novo->dir = NULL;
        strcpy(novo->nome, nm);
        novo->quant = 1;
        novo->vida = true;
        *n = novo;
    }
}

void matar(no **n, const char *nm)
{
    if (*n)
    {
        no *n0 = *n;
        int i = strcmp(n0->nome, nm);
        if (i > 0)
            matar(&n0->esq, nm);
        else if (i < 0)
            matar(&n0->dir, nm);
        else
            n0->vida = false;
    }
}

void marcarMortos(const no *m, no **v)
{
    if (m)
    {
        matar(v, m->nome);
        marcarMortos(m->esq, v);
        marcarMortos(m->dir, v);
    }
}

void exibir(const no *n)
{
    if (n)
    {
        exibir(n->esq);
        if (n->vida)
            printf("%s %d\n", n->nome, n->quant);
        exibir(n->dir);
    }
}

int main()
{
    no *vivos = NULL;
    no *mortos = NULL;
    char assassino[15];
    char assassinado[15];

    while (scanf("%s %s", assassino, assassinado) != EOF)
    {
        adicionar(&vivos, assassino);
        adicionar(&mortos, assassinado);
    }

    marcarMortos(mortos, &vivos);

    printf("HALL OF MURDERERS\n");
    exibir(vivos);

    return 0;
}