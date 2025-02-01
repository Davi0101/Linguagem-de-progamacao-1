#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, q, achei  = 0;
   

    char S[100001];
    char R[101];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]", S);                    //insercao string S

        scanf("%d",&q);
        for (int j = 0; j < q; j++)             //numero de testes
        {
            scanf(" %[^\n]",R);                 //insersao string R
            achei  = 0;
            for(int l = 0; S[l] != '\0' && R[achei] != '\0'; l++)
            {
                if (S[l]== R[achei])             //testa se as posicoes sao iguais
                {                                //se for igual vai incrementado o vetor R, e testa a proxima posicao
                    achei ++;
                }    
            }
            if (R[achei] == '\0')                // se chegar no fim do vetor R e pq existe uma sequencia igua no vetor S
                {
                    printf("Yes\n");
                }
                
                else                             // caso contrario nao tem a quencia buscada no vetor S
                {
                    printf("No\n");
                }
            

        }
        
    }
    
    


    return 0;
}
