#include <stdio.h>
#include <stdlib.h>

// Função para mostrar o vetor
void mostrarVet(int *p, int t) {
    for (int i = 0; i < t; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

// Função para organizar o vetor como um heap máximo
void heapify(int *a, int n, int i) {
    int maior = i;        // Inicializa maior como raiz
    int esquerdo = 2 * i + 1;  // Esquerdo = 2*i + 1
    int direito = 2 * i + 2;   // Direito = 2*i + 2

    // Verifica se o filho esquerdo existe e é maior que a raiz
    if (esquerdo < n && a[esquerdo] > a[maior]) {
        maior = esquerdo;
    }

    // Verifica se o filho direito existe e é maior que a raiz
    if (direito < n && a[direito] > a[maior]) {
        maior = direito;
    }

    // Se a raiz não for a maior, troca com o maior dos filhos e continua heapificando
    if (maior != i) {
        // Troca a[i] com a[maior]
        int temp = a[i];
        a[i] = a[maior];
        a[maior] = temp;

        // Recursivamente heapifica a subárvore afetada
        heapify(a, n, maior);
    }
}

// Função principal para executar o algoritmo Heap Sort
void heapSort(int *a, int n) {
    // Constrói o heap máximo
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // Um a um, remove os elementos do heap e os coloca no final do vetor
    for (int i = n - 1; i > 0; i--) {
        // Troca a raiz (máximo) com o último elemento
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // Chama heapify na raiz para reorganizar o heap
        heapify(a, i, 0);
    }
}

int main() {
    int *p, tam;

    // Pergunta o tamanho do vetor
    printf("Quantidade de elementos do vetor? ");
    scanf("%d", &tam);

    // Aloca o vetor dinamicamente
    p = (int*) malloc(tam * sizeof(int));

    // Lê os valores para o vetor
    printf("\nDigite o conteudo do vetor:\n");
    for (int i = 0; i < tam; i++) {
        scanf("%d", &p[i]);
    }

    // Mostra o vetor antes de ordenar
    printf("\nConteudo digitado para o vetor:\n");
    mostrarVet(p, tam);

    // Ordena o vetor com Heap Sort
    printf("\nOrdenando o vetor...\n");
    heapSort(p, tam);

    // Mostra o vetor ordenado
    printf("\nConteudo do vetor ja ordenado:\n");
    mostrarVet(p, tam);

    // Libera a memória alocada
    free(p);

    return 0;
}
