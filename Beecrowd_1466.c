#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv {
    char info;
    struct arv *dir;
    struct arv *esq;
} No;

No *inserir_ArvB(char info, No *Raiz);
void print_nivel(No *Raiz);

int main() {
    char operacao[8];
    char info;
    No *arvore = NULL;
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

void print_nivel(No *Raiz){
    
}