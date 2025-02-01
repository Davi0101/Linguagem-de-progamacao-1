#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv {
    char info;
    struct arv *dir;
    struct arv *esq;
} No;

No *inserir_ArvB(char info, No *Raiz);
void print_ordenado(No *Raiz, int *primeiro);
void print_pre_ordenado(No *Raiz, int *primeiro);
void print_pos_ordenado(No *Raiz, int *primeiro);
int busca(No *Raiz, char c);

int main() {
    char operacao[8];
    char info;
    No *arvore = NULL;

    while (scanf("%s", operacao) != EOF) {
        if (strcmp(operacao, "I") == 0) {
            scanf(" %c", &info);
            arvore = inserir_ArvB(info, arvore);
        } else if (strcmp(operacao, "INFIXA") == 0) {
            int primeiro = 1;            
            print_ordenado(arvore, &primeiro);
            printf("\n");
        } else if (strcmp(operacao, "PREFIXA") == 0) {
            int primeiro = 1;
            print_pre_ordenado(arvore, &primeiro);
            printf("\n");
        } else if (strcmp(operacao, "POSFIXA") == 0) {
            int primeiro = 1;
            print_pos_ordenado(arvore, &primeiro);
            printf("\n");
        } else if (strcmp(operacao, "P") == 0) {
            scanf(" %c", &info);
            if (busca(arvore, info) == 1) {
                printf("%c existe\n", info);
            } else {
                printf("%c nao existe\n", info);
            }
        }
    }
    return 0;
}

No *inserir_ArvB(char info, No *Raiz) {
    if (Raiz == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->info = info;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    } else {
        if (info < Raiz->info) {
            Raiz->esq = inserir_ArvB(info, Raiz->esq);
        } else {
            Raiz->dir = inserir_ArvB(info, Raiz->dir);
        }
    }
    return Raiz;
}

void print_ordenado(No *Raiz, int *primeiro) {
    if (Raiz != NULL) {
        print_ordenado(Raiz->esq, primeiro);
        if (*primeiro) {
            *primeiro = 0;
        } else {
            printf(" ");
        }
        printf("%c", Raiz->info);
        print_ordenado(Raiz->dir, primeiro);
    }
}

void print_pre_ordenado(No *Raiz, int *primeiro) {
    if (Raiz != NULL) {
        if (*primeiro) {
            *primeiro = 0;
        } else {
            printf(" ");
        }
        printf("%c", Raiz->info);
        print_pre_ordenado(Raiz->esq, primeiro);
        print_pre_ordenado(Raiz->dir, primeiro);
    }
}

void print_pos_ordenado(No *Raiz, int *primeiro) {
    if (Raiz != NULL) {
        print_pos_ordenado(Raiz->esq, primeiro);
        print_pos_ordenado(Raiz->dir, primeiro);
        if (*primeiro) {
            *primeiro = 0;
        } else {
            printf(" ");
        }
        printf("%c", Raiz->info);
    }
}

int busca(No *Raiz, char c) {
    if (Raiz != NULL) {
        if (Raiz->info == c) {
            return 1;
        } else if (c < Raiz->info) {
            return busca(Raiz->esq, c);
        } else {
            return busca(Raiz->dir, c);
        }
    }
    return 0;
}
