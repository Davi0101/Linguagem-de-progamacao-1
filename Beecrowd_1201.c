#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv {
    int info;
    struct arv *dir;
    struct arv *esq;
} No;

No *inserir_ArvB(int info, No *Raiz);
void print_ordenado(No *Raiz, int *primeiro);
void print_pre_ordenado(No *Raiz, int *primeiro);
void print_pos_ordenado(No *Raiz, int *primeiro);
int busca(No *Raiz, int c);
No *remover(int c, No *raiz);
void liberar_arvore(No *raiz);

int main() {
    char operacao[8];
    int info;
    No *arvore = NULL;

    while (scanf("%s", operacao) != EOF) {
        if (strcmp(operacao, "I") == 0) {
            scanf(" %d", &info);
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
            scanf(" %d", &info);
            if (busca(arvore, info) == 1) {
                printf("%d existe\n", info);
            } else {
                printf("%d nao existe\n", info);
            }
        } else if (strcmp(operacao, "R") == 0) {
            scanf(" %d", &info);
            arvore = remover(info, arvore);
        }
    }

    
    liberar_arvore(arvore);
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

void print_ordenado(No *Raiz, int *primeiro) {
    if (Raiz != NULL) {
        print_ordenado(Raiz->esq, primeiro);
        if (*primeiro) {
            *primeiro = 0;
        } else {
            printf(" ");
        }
        printf("%d", Raiz->info);
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
        printf("%d", Raiz->info);
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
        printf("%d", Raiz->info);
    }
}

int busca(No *Raiz, int c) {
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

No *remover(int c, No *raiz) {
    if (raiz == NULL)
        return NULL;

    if (raiz->info > c) {
        raiz->esq = remover(c, raiz->esq);
    } else if (raiz->info < c) {
        raiz->dir = remover(c, raiz->dir);
    } else { 
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        } else if (raiz->esq == NULL) {
            No *temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            No *temp = raiz->esq;
            free(raiz);
            return temp;
        } else {
            No *aux = raiz->esq;
            while (aux->dir != NULL) {
                aux = aux->dir;
            }
            raiz->info = aux->info; 
            raiz->esq = remover(aux->info, raiz->esq);
        }
    }
    return raiz;
}


void liberar_arvore(No *raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esq);
        liberar_arvore(raiz->dir);
        free(raiz);
    }
}

