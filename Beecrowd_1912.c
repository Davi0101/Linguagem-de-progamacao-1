#include <stdio.h>


int main(void) {
    int n, alvo;

    while (scanf("%d %d", &n, &alvo) && n != 0 && alvo != 0) {
        int h[n];
        double soma = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &h[i]);
            soma += h[i];
        }

        if (alvo > soma) {
            printf("-.-\n");
            continue;
        }

        if (alvo == soma) {
            printf(":D\n");
            continue;
        }

        double corte = h[0];
        double esq = 0, dir = 10000;

        while (dir - esq > 1e-9) {
            corte = (esq + dir) / 2.0;
            soma = 0;

            for (int i = 0; i < n; i++) {
                if (h[i] > corte) {
                    soma += h[i] - corte;
                }
            }

            if (soma >= alvo) {
                esq = corte;
            } else {
                dir = corte;
            }
        }

        printf("%.4lf\n", corte);
    }

    return 0;
}
