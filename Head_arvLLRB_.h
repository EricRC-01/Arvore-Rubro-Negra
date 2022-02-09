


#include "Head_my_string_.h"

typedef struct node
{

	int chave;

	struct node *filho_esq;
    struct node *filho_dir;

	// vermelho ==> TRUE, preto ==> FALSE
	BOLL cor;

}nodeType;


//Criar um novo nó
nodeType* createNode(int data, BOLL color);

//Inserir na arvore (busca recursiva)
nodeType* inserir(nodeType* raiz, int chave);

//Rotação anti-hóraria
nodeType* rotateEsq(nodeType* raiz);

//Rotação hóraria
nodeType* rotateDir(nodeType* raiz);

//Retorna o nó maximo de uma arvore
nodeType *maximo(nodeType *arvore);

//Retorna o nó mínimo de uma arvore
nodeType *minimo(nodeType *arvore);

//Busca um nó de acordo com uma chave
nodeType *busca(nodeType *arvore, int chave);

//Retorna o nó que contem a chave predecessora da chave buscada 
nodeType *predecesor(nodeType *arvore, int chave);

//Retorna o nó que contem a chave sucessora da chave buscada 
nodeType *sucessor(nodeType *arvore, int chave);

//Verificar a cor do nó
int verCor(nodeType *raiz);

//Apagar uma arvore
nodeType *eraseTree(nodeType *corrent_node);

//Imprimir arvore da direita para esquerda
void printTreeORD(nodeType *pNode);

//Imprimir arvore da esquerda para direita
void printTreePRE(nodeType *pNode);

//Imprimir arvore da esquerda para direita
void printTreePOS(nodeType *pNode);

//Chamada da printTets 
void printTreeTest(nodeType *arvore);

//Printa uma arvore e seus filhos a cada recurção
void printTets(nodeType *pNode);
