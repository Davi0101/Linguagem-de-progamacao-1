
#include "arvore.h"




int main()
{
    int opcao;
    int val;
    No *arvore = NULL;
    do
    {
        printf("\nDigite uma operacao: \n1-para inserir um elemento \n2-para imprimir arvore \n3-para imprimir preordenado \n4- para imprimir posordenado\n0-para sair\n");
        scanf("%d",&opcao);

        if (opcao == 1)
        {
            printf("\nDigite o numero a ser inserido: ");
            scanf("%d",&val);
            arvore = inserir_ArvB(val, arvore);
            
        }
        else if (opcao == 2)
        {
            print_ordenado(arvore);
            
        }
        else if (opcao == 3)
        {
            print_pre_ordenado(arvore);
            
        }
        else if (opcao == 4)
        {
            print_pos_ordenado(arvore);
            
        }       
        else if (opcao != 0)
        {
            printf("Opcao invalida::::\n");
        }
        
        
    } while (opcao != 0);
        
    return 0;
}
