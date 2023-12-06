#pragma once


typedef int BBTData;

typedef struct BBTNode {
    BBTData data;
    int balance_factor;
    struct BBTNode* left;
    struct BBTNode* right;
} BBTNode;

// A árvore binária é apenas um encapsulamento de um nodo que pode agir como raíz
// Note qualquer nodo é também uma árvore binária
// Para utilizar funções que operam em árvores binárias fora da raíz, basta chamar BBTFromNode(nodo)
typedef struct BalancedBinaryTree {
    BBTNode* root;
} BalancedBinaryTree;

enum BBTSide {
    BBT_LEFT,
    BBT_RIGHT
};

enum BBTTraversal {
    BBT_TRAVERSAL_PRE,
    BBT_TRAVERSAL_IN,
    BBT_TRAVERSAL_POST
};


// Criar e alocar um novo nodo sem filhos na heap
// Retorna o nodo criado
BBTNode* BBTNewNode(BBTData data);

// Criar uma árvore vazia
BalancedBinaryTree BBTCreate();

// Criar uma nova árvore a partir de um nodo que será a raíz da árvore
BalancedBinaryTree BBTFromNode(BBTNode* root);

// Verificar se a árvore binária está vazia
BBTData BBTIsEmpty(BalancedBinaryTree tree);

// Inserir item na lista em ordem crescente
// Usar essa função para inserir itens na árvore
// Retorna o nodo do item inserido
// Não verifica se `tree` é NULL
BBTNode* BBTInsertOrdered(BalancedBinaryTree* tree, BBTData data);

// Buscar item na lista
// Retorna o nodo do item encontrado ou NULL caso não encontre
BBTNode* BBTSearch(BalancedBinaryTree tree, BBTData data);

// Caminhar por todos os itens da árvore, executando a função `operation`
// `operation` deve retornar 0 para continuar o caminhamento ou 1 para parar
// `traversal` define a ordem do caminhamento e `order` define a ordem dos filhos
// Retorna 1 se o caminhamento foi interrompido pela função `operation` e 0 caso contrário
// Não verifica se `tree` é NULL
// Cuidado para não remover a raíz da árvore durante o caminhamento
// Antes de usar, verifique se não há outras funções que possam fazer o que você quer, pois ela não é muito eficiente
int BBTForEach(BalancedBinaryTree tree, enum BBTTraversal traversal, enum BBTSide order, int (*operation)(BBTNode* node));

// Imprimir árvore
// Encapsulamento sobre BBTForEach() para imprimir a árvore
void BBTPrintList(BalancedBinaryTree tree, enum BBTTraversal traversal, enum BBTSide order);

// Romover item da lista
// Retorna 1 se encontrou o produto, 0 caso contrário
int BBTRemove(BalancedBinaryTree* tree, BBTData data);

// Esvazia a árvore
void BBTEmpty(BalancedBinaryTree* tree);
