#include <stdio.h>
#include <stdlib.h>

#define letras 11

int verificar(char **alunos, int N);
int forca(const char *nome);

int main(void) {
    int n;
    while (scanf("%d", &n) && n != 0) {
        char **alunos = (char **)malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++) {
            alunos[i] = (char *)malloc(letras * sizeof(char));
            scanf(" %[^\n]", alunos[i]);
        }

        int resposta = verificar(alunos, n);

        if (resposta != -1)
            printf("%s\n", alunos[resposta]);
        else
            printf("Impossibilidade de empate.\n");

        for (int i = 0; i < n; i++)
            free(alunos[i]);
        free(alunos);
    }
    return 0;
}

int verificar(char **alunos, int N) {
    long *forca_alunos = (long * )malloc(N * sizeof(long));
    long time_a = 0, time_b = 0, forca_a = 0, forca_b = 0;

    for (int i = 0; i < N; i++) {
        forca_alunos[i] = forca(alunos[i]);
        forca_a += forca_alunos[i];
        time_a += forca_alunos[i] * (N - i);
    }

    for (int i = N - 1; i >= 0; i--) {
        if (time_a == time_b) {
            free(forca_alunos);
            return i;
        }

        time_b += forca_b + forca_alunos[i];
        forca_b += forca_alunos[i];

        time_a -= forca_a;
        forca_a -= forca_alunos[i];
    }

    free(forca_alunos);
    return -1;
}

int forca(const char *nome) {
    int valor = 0;
    while (*nome)
        valor += *nome++;
    return valor;
}
