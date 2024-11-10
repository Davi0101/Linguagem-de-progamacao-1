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

    // fucao para inserir um elemento na arvore binaria
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
            if (info < Raiz->info )// se o valor for menor que a raiz percorre a esquerda ate encontrar o valor null e cria um novo no
            {
                Raiz->esq = inserir_ArvB(info, Raiz->esq);
            }
            else                            //caso contrario percorrer a direita do no ate encontrar o valor null e cria um novo no a direita
            {
                Raiz->dir = inserir_ArvB(info, Raiz->dir);
            }
        }
        
        return Raiz;
    }

    //imprime a arvore en ordem crescente
void print_ordenado(No *Raiz){
    if (Raiz!= NULL)
    {
        print_ordenado(Raiz->esq);
        printf("%d ",Raiz->info);
        print_ordenado(Raiz->dir);

    }
    
    //impreme a arvore pre ordenada
}
void print_pre_ordenado(No *Raiz){
    if (Raiz!= NULL)
    {
        printf("%d ",Raiz->info);
        print_ordenado(Raiz->esq);
        print_ordenado(Raiz->dir);
    }
    //imprime a arvore pos ordenada
}
void print_pos_ordenado(No *Raiz){
    if (Raiz!= NULL)
    {
        print_ordenado(Raiz->esq);
        print_ordenado(Raiz->dir);
        printf("%d ",Raiz->info);

    }
    
}

//calcula a altura da arvore
int altura(No *Raiz){
    if (Raiz == NULL)
    {
        return -1;
    }
    else
    {
        int esquerda = altura(Raiz->esq);
        int direita = altura(Raiz->dir);
        if (esquerda > direita)
        {
            return esquerda + 1;
        }
        else
        {
            return direita + 1;
        }
        
        
    }
    
    

}






//#include "arvore.c"
#endif

