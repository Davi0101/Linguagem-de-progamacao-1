#include <stdio.h>
#include <stdlib.h>

void ordencao(int vet[], int n);
int busca(int vet[], int n, int val);

int main() {
    int n, q, val, caso = 1;
    int vet[10000];

    while (1) {    
        scanf("%d %d", &n, &q);
        if (n == 0 && q == 0) {
            break;
        }
        
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &vet[i]);
        }
        
        ordencao(vet, n);
        printf("CASE# %d:\n", caso++);
        for (int i = 0; i < q; i++) {
            scanf("%d", &val);
            int b = busca(vet, n, val);
            if (b != -1) {
                printf("%d found at %d\n", val, b + 1);
            } else {
                printf("%d not found\n", val);
            }
        }
        
    }

    return 0;
}

void ordencao(int vet[], int n) {
    int aux = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

int busca(int vet[], int n, int val) {
    int inicio = 0, fim = n - 1, meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vet[meio] == val) {
            
            while (meio > 0 && vet[meio - 1] == val) {
                meio--;
            }
            return meio;
        } else if (vet[meio] < val) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}