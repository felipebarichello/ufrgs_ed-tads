#pragma once


typedef int BTData;

typedef struct BTNode {
    BTData data;
    struct BTNode* left;
    struct BTNode* right;
} BTNode;

// A árvore binária é apenas um encapsulamento de um nodo que pode agir como raíz
typedef struct BinaryTree {
    BTNode* root;
} BinaryTree;


// Criar e alocar um novo nodo sem filhos na heap
// Retorna o nodo criado
BTNode* BTNewNode(BTData data);

// Criar uma árvore vazia
BinaryTree BTCreate();

// Criar uma nova árvore a partir de um nodo que será a raíz da árvore
BinaryTree BTFromNode(BTNode* root);

// Verificar se a árvore binária está vazia
BTData BTIsEmpty(BinaryTree tree);

// Buscar item na lista
// Retorna o nodo do item encontrado ou NULL caso não encontre
BTNode* BTSearch(BinaryTree tree, BTData data);

// Inserir item na lista (em ordem crescente)
// Usar essa função para inserir itens na árvore
// Retorna o nodo do item inserido
BTNode* BTInsert(BinaryTree* tree, BTData data);

// Imprimir
void BTPrint(BTNode* head);

// Imprimir
// Retorna 1 se encontrou o produto, 0 caso contrário
int BTRemove(BTNode** head, int code);

// Destruir árvore
// A árvore binária é apenas um encapsulamento de um nodo que pode agir como raíz
void BTDestroy(BTNode** head);
