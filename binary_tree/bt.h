#pragma once


typedef int BTData;

typedef struct BTNode {
    BTData data;
    struct BTNode* left;
    struct BTNode* right;
} BTNode;

// A árvore binária é apenas um encapsulamento de um nodo que pode agir como raíz
// Note qualquer nodo é também uma árvore binária
// Para utilizar funções que operam em árvores binárias fora da raíz, basta chamar BTFromNode(nodo)
typedef struct BinaryTree {
    BTNode* root;
} BinaryTree;

enum Side {
    LEFT,
    RIGHT
};

enum Traversal {
    TRAVERSAL_PRE,
    TRAVERSAL_IN,
    TRAVERSAL_POST
};


// Criar e alocar um novo nodo sem filhos na heap
// Retorna o nodo criado
BTNode* BTNewNode(BTData data);

// Criar uma árvore vazia
BinaryTree BTCreate();

// Criar uma nova árvore a partir de um nodo que será a raíz da árvore
BinaryTree BTFromNode(BTNode* root);

// Verificar se a árvore binária está vazia
BTData BTIsEmpty(BinaryTree tree);

// Inserir item na lista em ordem crescente
// Usar essa função para inserir itens na árvore
// Retorna o nodo do item inserido
// Não verifica se `tree` é NULL
BTNode* BTInsertOrdered(BinaryTree* tree, BTData data);

// Buscar item na lista
// Retorna o nodo do item encontrado ou NULL caso não encontre
BTNode* BTSearch(BinaryTree tree, BTData data);

// Caminhar por todos os itens da árvore, executando a função `operation`
// `operation` deve retornar 0 para continuar o caminhamento ou 1 para parar
// `traversal` define a ordem do caminhamento e `order` define a ordem dos filhos
// Retorna 1 se o caminhamento foi interrompido pela função `operation` e 0 caso contrário
// Não verifica se `tree` é NULL
// Cuidado para não remover a raíz da árvore durante o caminhamento
// Antes de usar, verifique se não há outras funções que possam fazer o que você quer, pois ela não é muito eficiente
int BTForEach(BinaryTree tree, enum Traversal traversal, enum Side order, int (*operation)(BTNode* node));

// Imprimir árvore
// Encapsulamento sobre BTForEach() para imprimir a árvore
void BTPrintList(BinaryTree tree, enum Traversal traversal, enum Side order);

// Romover item da lista
// Retorna 1 se encontrou o produto, 0 caso contrário
int BTRemove(BinaryTree* tree, BTData data);

// Esvazia a árvore
void BTEmpty(BinaryTree* tree);
