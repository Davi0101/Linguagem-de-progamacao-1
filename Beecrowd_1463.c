#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    char val;
    bool pref;
    struct No *esq, *dir;
} No;

void addOp(No **raiz, char v) {
    if (*raiz == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->val = v;
        novo->pref = false;
        novo->esq = novo->dir = NULL;
        *raiz = novo;
    } else {
        No *cur = *raiz;
        if (!cur->esq)
            addOp(&cur->esq, v);
        else
            addOp(&cur->dir, v);
    }
}

void addSoma(No **raiz, char op) {
    No *novo = (No *)malloc(sizeof(No));
    novo->val = op;
    novo->esq = *raiz;
    novo->dir = NULL;
    *raiz = novo;
}

void addMult(No **raiz, char op) {
    No *novo = (No *)malloc(sizeof(No));
    novo->val = op;
    novo->dir = NULL;

    if (((*raiz)->val == '+' || (*raiz)->val == '-') && !(*raiz)->pref) {
        novo->esq = (*raiz)->dir;
        (*raiz)->dir = novo;
    } else {
        novo->esq = *raiz;
        *raiz = novo;
    }
}

void procParenteses(No **raiz) {
    No *sub = NULL;
    char c;
    while (scanf("%c", &c) && c != ')') {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            addOp(&sub, c);
        else if (c == '+' || c == '-')
            addSoma(&sub, c);
        else if (c == '*' || c == '/')
            addMult(&sub, c);
    }
    sub->pref = true;

    if (*raiz == NULL) {
        *raiz = sub;
    } else {
        No *cur = *raiz;
        while (cur->esq && cur->dir)
            cur = cur->dir;
        if (!cur->esq)
            cur->esq = sub;
        else
            cur->dir = sub;
    }
}

void printNivel(const No *raiz, int atual, int alvo) {
    if (raiz) {
        if (atual < alvo) {
            printNivel(raiz->esq, atual + 1, alvo);
            printNivel(raiz->dir, atual + 1, alvo);
        } else if (atual == alvo) {
            printf("%c", raiz->val);
        }
    }
}

int altura(No *raiz) {
    if (raiz) {
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);
        return (esq > dir ? esq : dir) + 1;
    }
    return -1;
}

void limpar(No **raiz) {
    if (*raiz) {
        limpar(&(*raiz)->esq);
        limpar(&(*raiz)->dir);
        free(*raiz);
        *raiz = NULL;
    }
}

void printArvore(No *raiz) {
    int alt = altura(raiz);
    for (int i = 0; i <= alt; i++) {
        printf("Nivel %d: ", i);
        printNivel(raiz, 0, i);
        printf("\n");
    }
}

int main() {
    No *raiz = NULL;
    char c;
    bool novaLinha = false;

    while (scanf("%c", &c) != EOF) {
        if (novaLinha) {
            printf("\n");
            novaLinha = false;
        }

        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            addOp(&raiz, c);
        else if (c == '+' || c == '-')
            addSoma(&raiz, c);
        else if (c == '*' || c == '/')
            addMult(&raiz, c);
        else if (c == '(')
            procParenteses(&raiz);
        else if (c == '\n') {
            printArvore(raiz);
            novaLinha = true;
            limpar(&raiz);
        }
    }

    if (raiz) {
        printArvore(raiz);
        limpar(&raiz);
    }

    return 0;
}
