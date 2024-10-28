#ifndef arvore_h
#define arvore_h
#include <stdio.h>
#include <stdlib.h>



    typedef struct arv
    {
        int info;
        struct arv *dir;
        struct arv *esq;

    }No;


    No *inserir_ArvB(int info, No *Raiz)
    {
        if(Raiz == NULL){
            No *novo = (No*)malloc(sizeof(No));
            novo->info = info;
            novo->esq = NULL;
            novo->dir = NULL;
            return novo;

        }
        else
        {
            if (info < Raiz->info )
            {
                Raiz->esq = inserir_ArvB(info, Raiz->esq);
            }
            else
            {
                Raiz->dir = inserir_ArvB(info, Raiz->dir);
            }
        }
        
        return Raiz;
    }

void print_ordenado(No *Raiz){
    if (Raiz!= NULL)
    {
        print_ordenado(Raiz->esq);
        printf("%d ",Raiz->info);
        print_ordenado(Raiz->dir);

    }
    
}
void print_pre_ordenado(No *Raiz){
    if (Raiz!= NULL)
    {
        printf("%d ",Raiz->info);
        print_ordenado(Raiz->esq);
        print_ordenado(Raiz->dir);
    }
    
}
void print_pos_ordenado(No *Raiz){
    if (Raiz!= NULL)
    {
        print_ordenado(Raiz->esq);
        print_ordenado(Raiz->dir);
        printf("%d ",Raiz->info);

    }
    
}





//#include "arvore.c"
#endif

