#include <stdio.h>
#include <stdlib.h>

// Função para ordenar o vetor usando Heap Sort
void heapSort(int *a, int n) {
    // Construção do heap inicial
    for (int i = n / 2 - 1; i >= 0; i--) {
        int pai = i, t = a[pai];
        int filho = pai * 2 + 1;

        while (filho < n) {
            // Verifica se o filho da direita é maior que o filho da esquerda
            if (filho + 1 < n && a[filho + 1] > a[filho]) {
                // Atualiza para considerar o maior filho
                filho++;
            }

            // Verifica se o maior filho é maior que o pai
            if (a[filho] > t) {
                // Move o maior filho para cima
                a[pai] = a[filho];
                pai = filho;
                filho = pai * 2 + 1; // Avança para o próximo nível
            } else {
                // Se o pai for maior ou igual aos filhos, o heap está ajustado
                break;
            }
        }
        a[pai] = t; // Posiciona o elemento original no lugar correto
    }

    // Ordenação por remoção do maior elemento
    for (int i = n - 1; i > 0; i--) {
        // Troca o maior elemento (raiz do heap) com o último elemento não ordenado
        int t = a[0];
        a[0] = a[i];
        a[i] = t;

        int pai = 0, filho = pai * 2 + 1;
        while (filho < i) {
            // Verifica se o filho da direita é maior que o filho da esquerda
            if (filho + 1 < i && a[filho + 1] > a[filho]) {
                // Atualiza para considerar o maior filho
                filho++;
            }

            // Verifica se o maior filho é maior que o pai
            if (a[filho] > a[pai]) {
                // Move o maior filho para cima
                t = a[pai];
                a[pai] = a[filho];
                a[filho] = t;

                pai = filho;
                filho = pai * 2 + 1; // Avança para o próximo nível
            } else {
                // Se o pai for maior ou igual aos filhos, o heap está ajustado
                break;
            }
        }
        printf("\nConteúdo do vetor já ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    }
    
}

// Função principal
int main() {
    int *p;
    int tam = 7;

    printf("Quantidade de elementos do vetor? ");
  //  scanf("%d", &tam);

    p = (int *)malloc(tam * sizeof(int));
    if (p == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Leitura do vetor
    printf("\nDigite o conteúdo do vetor:\n");
    /*for (int i = 0; i < tam; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &p[i]);
    }*/
    p[0] = 40;
    p[1] = 90;
    p[2] = 20;
    p[3] = 10;
    p[4] = 50;
    p[5] = 70;
    p[6] = 80;
    // Exibição do vetor antes da ordenação
    printf("\nConteúdo digitado para o vetor:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", p[i]);
   }
    

    printf("\n");

    // Ordenação do vetor
    printf("\nOrdenando o vetor...\n");
    heapSort(p, tam);

    // Exibição do vetor após a ordenação
    printf("\nConteúdo do vetor já ordenado:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    free(p);
    return 0;
}
