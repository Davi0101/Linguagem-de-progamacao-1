#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noArv{
	char letra;              
	struct noArv *direita;   
	struct noArv *esquerda;  
} Arv;

int indice;

Arv* CriarNo(char letra)
{
	Arv *no = (Arv *) malloc(sizeof(Arv));  
	no->letra = letra;  
	no->esquerda = no->direita = NULL;  

	return no;
}


int buscarIndice(char *vet, int inicio, int fim, char letra)
{
	for (int i = inicio; i <= fim; ++i){  
		if (vet[i] == letra){  
			return i;
		}
	}
	return -1; 
}


Arv* construirArvore(char *EmOrdem, char *PreOrdem, int EmOrdemIni, int EmOrdemFim)
{
	
	if (EmOrdemIni > EmOrdemFim){
		return NULL;
	}
	
	Arv *no = CriarNo(PreOrdem[indice++]);  

	
	if (EmOrdemIni == EmOrdemFim){
		return no;
	}

	else{
	int indiceInfixa = buscarIndice(EmOrdem, EmOrdemIni, EmOrdemFim, no->letra);
	no->esquerda = construirArvore(EmOrdem, PreOrdem, EmOrdemIni, indiceInfixa - 1);
	no->direita = construirArvore(EmOrdem, PreOrdem, indiceInfixa + 1, EmOrdemFim);
	}
	
	return no;
}


void exibirPosfixa(Arv *no)
{
	if (no == NULL) {
		return;
  }
  else{
	exibirPosfixa(no->esquerda);
	exibirPosfixa(no->direita);
	printf("%c", no->letra);
	}
}


int main ()
{
	int numCasos;  
	char PreOrdem[27]; 
  char EmOrdem[27];  

	
	while (scanf("%s %s", PreOrdem, EmOrdem) != EOF)
	{
		int tam = strlen(PreOrdem);  
		indice = 0;  
		Arv *raiz = construirArvore(EmOrdem, PreOrdem, 0, tam - 1);  
		exibirPosfixa(raiz); 
		printf("\n");  
	}
}
