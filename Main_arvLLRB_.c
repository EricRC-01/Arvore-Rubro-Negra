/*******************************************************************************
*                       USP - Universidade de São Paulo                        *
*            ICMC - Instituto de Ciências Matemáticas e de Computação          *
********************************************************************************
*                 Eric Rodrigues das Chagas  NºUSP: 12623971                   *
*                  Bacharelado em Ciências de Computação 2021                  *
********************************************************************************
*                            Arvore Rubro Negra                                *  
*                   Algoritmos e Estruturas de Dados I SCC0202                 *  
********************************************************************************/




#include <stdio.h>
#include <stdlib.h>
#include "Head_my_string_.h"
#include "Head_arvLLRB_.h"



int main(){

    //Declarações iniciais
    nodeType *arvore = NULL;
    int comando = 0;
    int qnt_inputs = 0;
    int valor = 0;

    scanf("%d",&qnt_inputs);
    for (int i = 0; i < qnt_inputs; i++)
    {
        scanf("%d",&comando);
        
        //Inserção 
        if(comando == 1){
            scanf("%d",&valor);

            arvore = inserir(arvore,valor);
        }

        //Sucessor
        if(comando == 2){
            scanf("%d",&valor);
            nodeType *node_sucessor =  sucessor(arvore,valor);

            if(node_sucessor == NULL) printf("erro\n");
            else printf("%d\n",node_sucessor->chave);
        }
        
        //Predecessor
        if(comando == 3){
            scanf("%d",&valor);
            nodeType *node_predecessor = predecesor(arvore,valor);

            if(node_predecessor == NULL) printf("erro\n");
            else printf("%d\n",node_predecessor->chave);
        }

        //Máximo
        if(comando == 4){
            nodeType *node_maximo = maximo(arvore);
            printf("%d\n",node_maximo->chave);
        }

        //Mínimo
        if(comando == 5){
            nodeType *node_minimo = minimo(arvore);
            printf("%d\n",node_minimo->chave);
        }

        //Pré ordem
        if(comando == 6){
            if(arvore != NULL){ 
                printTreePRE(arvore); printf("\n");
            }
            else printf("erro\n");
        }

        //Em ordem
        if(comando == 7){
            if(arvore != NULL){ 
                printTreeORD(arvore); printf("\n");
            }else printf("erro\n");
        }

        //Pós ordem
        if(comando == 8){
            if(arvore != NULL){ 
                printTreePOS(arvore); printf("\n");
            }else printf("erro\n");
        }
    }

    eraseTree(arvore);
    return 0;
}


