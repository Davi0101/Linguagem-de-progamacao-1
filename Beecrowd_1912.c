#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, q, cont1, cont2, achei  = 0;
   

    char S[100001];
    char R[101];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]", S);

        cont1 = strlen(S);       //tamanho da string s
        scanf("%d",&q);
        for (int j = 0; j < q; j++)
        {
            scanf(" %[^\n]",R);

            cont2 = strlen(R);                   //tamanho da string r
            achei  = 0;
            for(int l = 0; S[l] != '\0' && R[achei] != '\0'; l++)
            {
                
                if (S[l]== R[achei])
                {
                    achei ++;
                }    
            }
            if (R[achei] == '\0')
                {
                    printf("Yes\n");
                }
                
                else
                {
                    printf("No\n");
                }
            

        }
        
    }
    
    


    return 0;
}
