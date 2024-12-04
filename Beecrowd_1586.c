#include <stdio.h>
#include <stdlib.h>

#define letras 11  // Define o número máximo de caracteres para cada nome, incluindo o terminador nulo '\0'.


int verificar(char **alunos, int N);
int forca(const char *nome);

int main(void) {
    int n;
    
    // Loop principal que continua enquanto o número de alunos lido for diferente de 0.
    while (scanf("%d", &n) && n != 0) {
        // Aloca um vetor de ponteiros para alunos.
        char **alunos = (char **)malloc(n * sizeof(char *));
        
        for (int i = 0; i < n; i++) {
            // Aloca espaço para armazenar o nome de cada aluno
            alunos[i] = (char *)malloc(letras * sizeof(char));
            // Lê o nome do aluno, incluindo espaços
            scanf(" %[^\n]", alunos[i]);
        }

        // Chama a função verificar, que retorna o índice do aluno que permite o equilíbrio ou -1.
        int resposta = verificar(alunos, n);

        if (resposta != -1)
            // Se encontrar uma posição de equilíbrio, imprime o nome do aluno.
            printf("%s\n", alunos[resposta]);
        else
            // Caso contrário, imprime que não é possível o empate.
            printf("Impossibilidade de empate.\n");

        // Libera a memória alocada para cada nome.
        for (int i = 0; i < n; i++)
            free(alunos[i]);
        
        // Libera a memória alocada para o vetor de ponteiros.
        free(alunos);
    }
    return 0;
}

// Função que verifica se é possível dividir os alunos em dois times com forças equilibradas.
int verificar(char **alunos, int N) {
    // Aloca memória para armazenar a força de cada aluno.
    long *forca_alunos = (long *)malloc(N * sizeof(long));
    long time_a = 0, time_b = 0; // Somatórios ponderados das forças dos dois times.
    long forca_a = 0, forca_b = 0; // Somatórios simples das forças dos dois grupos.

    // Calcula a força de cada aluno e o somatório ponderado do "time A".
    for (int i = 0; i < N; i++) {
        forca_alunos[i] = forca(alunos[i]); // Calcula a força de cada nome.
        forca_a += forca_alunos[i];         // Soma simples das forças.
        time_a += forca_alunos[i] * (N - i); // Soma ponderada das forças.
    }

    // Percorre o vetor de trás para frente tentando equilibrar os times.
    for (int i = N - 1; i >= 0; i--) {
        // Se as forças ponderadas forem iguais, retorna o índice atual.
        if (time_a == time_b) {
            free(forca_alunos); // Libera a memória antes de retornar.
            return i;
        }

        // Ajusta as forças para o próximo passo.
        time_b += forca_b + forca_alunos[i]; // Atualiza a soma ponderada do "time B".
        forca_b += forca_alunos[i];          // Atualiza a soma simples do "time B".

        time_a -= forca_a;                   // Subtrai a soma ponderada do "time A".
        forca_a -= forca_alunos[i];          // Subtrai a soma simples do "time A".
    }

    free(forca_alunos); // Libera a memória se não encontrou uma solução.
    return -1;          // Retorna -1 se não foi possível encontrar o equilíbrio.
}

// Função que calcula a "força" de um nome, somando os valores ASCII dos caracteres.
int forca(const char *nome) {
    int valor = 0;
    while (*nome) // Itera até o final da string.
        valor += *nome++; // Soma o valor ASCII de cada caractere e avança o ponteiro.
    return valor;
}
