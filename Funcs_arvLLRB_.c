/************************************************************
*            Eric Rodrigues das Chagas                      *
*    [ICMC - Bacharelado em Ciências da Computação - 2021]  *
*    NºUSP: 12623971                                        *
* ||----------------------Contatos----------------------||  *
*            Telegram [ @EricRC_123 ]                       *
*            Email  [ eric.r.c@usp.br ]                     *
*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Head_my_string_.h"
#include "Head_arvLLRB_.h"


//Criar um novo nó
nodeType* createNode(int chave, BOLL color)
{
	nodeType *newNode = (nodeType *) malloc(sizeof(nodeType));
	newNode->filho_esq = NULL;
    newNode->filho_dir = NULL;
	newNode->chave = chave;

	newNode->cor = TRUE;
	return newNode;
}

//Rotação anti-hóraria
nodeType* rotateEsq(nodeType* raiz)
{
	nodeType *novaRaiz = raiz->filho_dir;
	nodeType *childLeft = novaRaiz->filho_esq;

	novaRaiz->filho_esq = raiz;
	raiz->filho_dir = childLeft;

	return novaRaiz;
}

//Rotação hóraria
nodeType* rotateDir(nodeType* raiz)
{
	nodeType *novaRaiz = raiz->filho_esq;
	nodeType *childRight = novaRaiz->filho_dir;

	novaRaiz->filho_dir = raiz;
	raiz->filho_esq = childRight;
	
	return novaRaiz;
}

//Verificar a cor do nó
int verCor(nodeType *raiz)
{
	if(raiz == NULL) return FALSE;
	    
	return (raiz->cor == TRUE);
}

//Trocar a cor dos nós
void trocarCor(nodeType *node1, nodeType *node2)
{
	BOLL cor_aux = node1->cor;
	node1->cor = node2->cor;
	node2->cor = cor_aux;
}

// Inserir na arvore (busca recursiva)
nodeType* inserir(nodeType* raiz, int chave)
{
    //Caso base, inserir
	if (raiz == NULL)
		return createNode(chave, FALSE);

    //Caso: ir para o nó esquerdo
	if (chave < raiz->chave)
		raiz->filho_esq = inserir(raiz->filho_esq, chave);

    //Caso: ir para o nó direito
	else if (chave > raiz->chave)
		raiz->filho_dir = inserir(raiz->filho_dir, chave);

	else if(chave == raiz->chave){
		return raiz;
        raiz->cor;
    }
	
    //Caso 1:
	//filho direito é vermelho mas esquerdo é preto
	if (verCor(raiz->filho_dir) && !verCor(raiz->filho_esq))
	{
		raiz = rotateEsq(raiz);

		//O filho a esquerda deve sempre ser vermelho
		trocarCor(raiz, raiz->filho_esq);
		
	}
	
	//Caso 2:
	//quando o filho a esquerda e o filho do filho esquerdo são vermelhos
	if (verCor(raiz->filho_esq) && verCor(raiz->filho_esq->filho_esq))
	{
		raiz = rotateDir(raiz);
		trocarCor(raiz, raiz->filho_dir);
	}
	
	
	//Caso 3:
	//quando ambos  os filhos direito e esquerdo são vermelhos
	if (verCor(raiz->filho_esq) && verCor(raiz->filho_dir))
	{
        //Inverter a cor dos nós
		raiz->cor = !raiz->cor;

		//Mudar cores para preto
		raiz->filho_esq->cor = FALSE;
		raiz->filho_dir->cor = FALSE;
	}

	return raiz;
}

//Retorna o nó maximo de uma arvore
nodeType *maximo(nodeType *arvore)
{
    if(arvore == NULL) return NULL;
    nodeType *corrent_node = arvore;

    while (corrent_node->filho_dir != NULL)
    {
        corrent_node = corrent_node->filho_dir;
    }

    return corrent_node;
}

//Retorna o nó mínimo de uma arvore
nodeType *minimo(nodeType *arvore)
{
    if(arvore == NULL) return NULL;
    nodeType *corrent_node = arvore;

    while (corrent_node->filho_esq != NULL)
    {
        corrent_node = corrent_node->filho_esq;
    }

    return corrent_node;
}

//Busca um nó de acordo com uma chave
nodeType *busca(nodeType *arvore, int chave)
{
    if(arvore == NULL) return NULL;
    nodeType *corrent_node = arvore;

    while ( corrent_node->filho_dir  != NULL && 
            corrent_node->filho_esq  != NULL   )
    {
        if (chave == corrent_node->chave){
            return corrent_node;
        }
        else if(chave > corrent_node->chave){
            corrent_node = corrent_node->filho_dir;
        }
        else if(chave < corrent_node->chave){
            corrent_node = corrent_node->filho_esq;
        }
        printf("\n");    
    }
    if(chave == corrent_node->chave) return corrent_node;    

    if( corrent_node->filho_dir == NULL){
        printf("corrent_node->filho_dir == NULL\n");
        if(chave < corrent_node->chave){
            return busca(corrent_node->filho_esq,chave);
        }
        else{
            return NULL;  
        }
    }
    if( corrent_node->filho_esq == NULL){
        printf("corrent_node->filho_esq == NULL\n");
        if(chave > corrent_node->chave){
            return busca(corrent_node->filho_dir,chave);
        }
        else{
            return NULL;
        }
    }
    printf("Error > busca\n");
    return NULL;
}

//Busca o nó imediatamente anterior a chave dada
nodeType *predecesor(nodeType *arvore, int chave)
{
    if(arvore == NULL) return NULL;
    nodeType *corrent_node = arvore;
    nodeType *node_pai = NULL;

    //Busca
    while ( corrent_node->filho_dir  != NULL && 
            corrent_node->filho_esq  != NULL   )
    {
        if (chave == corrent_node->chave){
            break;
        }
        else if(chave > corrent_node->chave){
            node_pai = corrent_node;
            corrent_node = corrent_node->filho_dir;
        }
        else if(chave < corrent_node->chave){
            node_pai = corrent_node;
            corrent_node = corrent_node->filho_esq;
        }
    }

    //Caso: não existem chaves menores que a chave atual
    if(corrent_node->filho_esq == NULL){
        if(node_pai->chave < chave)
            return node_pai;
        else return NULL;
    }
    
    //Encontrar o menor nó da sub-arvore esquerda
    nodeType *node_menor = maximo(corrent_node->filho_esq);
    
    if(node_menor->chave == chave) return NULL;
    
    return node_menor;
}

//Busca o nó imediatamente posterior a chave dada
nodeType *sucessor(nodeType *arvore, int chave)
{
    if(arvore == NULL) return NULL;
    nodeType *corrent_node = arvore;
    nodeType *node_pai = NULL;

    //Busca
    while ( corrent_node->filho_dir  != NULL && 
            corrent_node->filho_esq  != NULL   )
    {
        if (chave == corrent_node->chave){
            break;
        }
        else if(chave > corrent_node->chave){
            node_pai = corrent_node;
            corrent_node = corrent_node->filho_dir;
        }
        else if(chave < corrent_node->chave){
            node_pai = corrent_node;
            corrent_node = corrent_node->filho_esq;
        }
    }
    
    //Caso: não existem chaves maiores que a atual
    if(corrent_node->filho_dir == NULL){    
        if(node_pai->chave > chave )
            return node_pai;
        else return NULL;
    }
    nodeType *node_maximo = minimo(corrent_node->filho_dir);
    if(node_maximo->chave == chave){ 
        return NULL;
    }
    return node_maximo;
}

//Apaga uma arvore
nodeType *eraseTree(nodeType *corrent_node)
{
    //Caso base
    if(corrent_node == NULL){
        return NULL;
    }
    nodeType *erase_node = NULL;

    if(corrent_node->filho_esq != NULL){
        erase_node = eraseTree(corrent_node->filho_esq);
        free(erase_node);
    }

    if(corrent_node->filho_dir != NULL){
        corrent_node = eraseTree(corrent_node->filho_dir);
        free(erase_node);
    }

    free(corrent_node);
    return NULL;
}

//Imprimir arvore da direita para esquerda
void printTreeORD(nodeType *pNode) 
{

    if(pNode == NULL){
        //printf("null\n");
        return;
    }
    
    
    //printf("Direita do (%i) \n",pNode->num);
    printTreeORD(pNode->filho_esq);

    printf("%d ",pNode->chave);

    printTreeORD(pNode->filho_dir);
    
    //printf("Esquerda do (%i)\n",pNode->num);

    return;
}

//Imprimir arvore da esquerda para direita
void printTreePRE(nodeType *pNode)
{
    if(pNode != NULL){
		//printf("------Node atual  ");
		printf("%d ",pNode->chave);
		//printf("------\n");
	}
	else {
		//printf("------Node atual ( NULL )------\n");
		return;
	}
	
	//Prints test
	/* 	
		if(pNode->filho_dir != NULL) 
			printf("Filho direito = (%i, %i)\n",pNode->filho_d) ave, pNode->fi);
		
		else printf("Filho direito = NULL\n");

		if(pNode->filho_esq != NULL) 
			printf("Filho esquerdo = (%i, %i)\n",pNode->filho_e) ave, pNode->fi);
		
		else printf("Filho esquerdo = NULL\n");

    */
	
	//printf("Esquerda do (%i)\n",pNode->num);
    printTreePRE(pNode->filho_esq);
	//printf("Direita do (%i) \n",pNode->num);
	printTreePRE(pNode->filho_dir);

	

    return;
}

//Imprimir arvore da esquerda para direita
void printTreePOS(nodeType *pNode)
{
    if(pNode != NULL){
		//printf("------Node atual  ");
		
	    printTreePOS(pNode->filho_esq);

		printTreePOS(pNode->filho_dir);

		
		printf("%d ",pNode->chave);
		//printf("------\n");
	}
	
    return;
}

//Chamada da printTets (para fins de depuração)
void printTreeTest(nodeType *arvore) {
    printf("¨¨¨¨¨¨¨¨¨¨¨¨ARVORE¨¨¨¨¨¨¨¨¨¨¨¨\n");
    printTets(arvore);
    printf("¨¨¨¨¨¨¨¨¨¨¨¨FIM¨¨¨¨¨¨¨¨¨¨¨¨\n\n");
}

//Printa uma arvore e seus filhos a cada recurção (para fins de depuração)
void printTets(nodeType *pNode)
{
    if(pNode == NULL){ 
        printf("------NODE ATUAL  NULL -----\n");
        return;
    }

    printf("------Node atual  %i -----\n",pNode->chave);

    if(pNode->filho_esq != NULL && pNode->filho_dir != NULL)
        printf("Esquerdo (%i) -- Direito (%i) \n",pNode->filho_esq->chave,pNode->filho_dir->chave);

    else if(pNode->filho_esq != NULL && pNode->filho_dir == NULL)
        printf("Esquerdo (%i) -- Direito (null) \n",pNode->filho_esq->chave);

    else if(pNode->filho_esq == NULL && pNode->filho_dir != NULL)
        printf("Esquerdo (null) -- Direito (%i) \n",pNode->filho_dir->chave);
    
    else if(pNode->filho_esq == NULL && pNode->filho_dir == NULL)
        printf("Esquerdo (null) -- Direito (null)) \n");

    printf("\n");
    printTets(pNode->filho_esq);
    printTets(pNode->filho_dir);


    return;
}