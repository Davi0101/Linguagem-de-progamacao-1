#include <stdio.h>
#include <stdlib.h>
#define MAX 1000 

typedef struct arv {
    int info;
    struct arv *dir;
    struct arv *esq;
} No;

No *inserir_ArvB(int info, No *Raiz);
void percurso_nivel(No *Raiz);
void liberar_arvore(No *raiz);
void enfileirar(No *no);
No *desenfileirar();
No *fila[MAX];

int frente = 0, tras = 0;

int main() {
    int C;
    scanf("%d", &C); 

    for (int caso = 1; caso <= C; caso++) {

        frente = 0;
        tras = 0;

        int N;
        scanf("%d", &N); 
        No *arvore = NULL;

        for (int i = 0; i < N; i++) {
            int valor;
            scanf("%d", &valor); 
            arvore = inserir_ArvB(valor, arvore);
        }

        printf("Case %d:\n", caso);
        percurso_nivel(arvore); 
        printf("\n\n");
            
        
    }

    return 0;
}

No *inserir_ArvB(int info, No *Raiz) {
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

void enfileirar(No *no) {
    if (tras < MAX) { 
        fila[tras++] = no;
    }
}

No *desenfileirar() {
    return fila[frente++];
}

void percurso_nivel(No *Raiz) {
    if (Raiz == NULL) {
        return;
    }

    enfileirar(Raiz);
    int primeiro = 1;

    while (frente < tras) {
        No *noAtual = desenfileirar();
        if (!primeiro) {
            printf(" "); 
        } else {
            primeiro = 0;  
        }
        printf("%d", noAtual->info);
        
        if (noAtual->esq != NULL) {
            enfileirar(noAtual->esq); 
        }
        if (noAtual->dir != NULL) {
            enfileirar(noAtual->dir); 
        }
    }
    
}
