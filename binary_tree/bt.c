#include <stdlib.h>
#include <stdio.h>
#include "bt.h"


BTNode* BTNewNode(BTData data) {
    BTNode* new_node = (BTNode*) malloc(sizeof(BTNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

BinaryTree BTCreate() {
    return (BinaryTree) { NULL };
}

BinaryTree BTFromNode(BTNode* root) {
    return (BinaryTree) { root };
}

BTData BTIsEmpty(BinaryTree tree) {
    return !tree.root;
}

BTNode* BTInsertOrdered(BinaryTree* tree, BTData data) {
    if (BTIsEmpty(*tree)) {
        tree->root = BTNewNode(data);
        return tree->root;
    }

    BTNode* current_node = tree->root;

    for (;;) {
        if (data < current_node->data) {
            if (!current_node->left) {
                current_node->left = BTNewNode(data);
                return current_node->left;
            }

            current_node = current_node->left;
        } else if (data > current_node->data) {
            if (!current_node->right) {
                current_node->right = BTNewNode(data);
                return current_node->right;
            }

            current_node = current_node->right;
        } else {
            return NULL;
        }
    }
}

BTNode* BTSearch(BinaryTree tree, BTData data) {
    BTNode* current_node = tree.root;

    while (current_node) {
        if (data < current_node->data) {
            current_node = current_node->left;
        } else if (data > current_node->data) {
            current_node = current_node->right;
        } else {
            return current_node;
        }
    }

    return NULL;
}

// Função recursiva interna para BTForEach()
// Não exposta no header
int _BTForEach(BTNode* node, enum Traversal traversal, enum Side order, int (*operation)(BTNode* node)) {
    if (!node) {
        return 0;
    }

    BTNode* first_child;
    BTNode* second_child;

    switch (order) {
        case LEFT: {
            first_child = node->left;
            second_child = node->right;
            break;
        }

        case RIGHT: {
            first_child = node->right;
            second_child = node->left;
            break;
        }
    }

    if (traversal == TRAVERSAL_PRE)
        if (operation(node))
            return 1;

    if (_BTForEach(first_child, traversal, order, operation))
        return 1;

    if (traversal == TRAVERSAL_IN)
        if (operation(node))
            return 1;

    if (_BTForEach(second_child, traversal, order, operation))
        return 1;

    if (traversal == TRAVERSAL_POST)
        if (operation(node))
            return 1;
    
    return 0;
}

int BTForEach(BinaryTree tree, enum Traversal traversal, enum Side order, int (*operation)(BTNode* node)) {
    return _BTForEach(tree.root, traversal, order, operation);
}

// Função interna para BTPrintList()
// Não exposta no header
int _BTPrintNode_print(BTNode* node) {
    printf("%d ", node->data);
    return 0;
}

void BTPrintList(BinaryTree tree, enum Traversal traversal, enum Side order) {
    printf("[ ");
    _BTForEach(tree.root, traversal, order, _BTPrintNode_print);
    printf("]\n");
}

int BTRemove(BinaryTree* tree, BTData data) {
    if (BTIsEmpty(*tree)) {
        return 0;
    }

    int found = 0;
    enum Side last_side;
    BTNode* current_node = tree->root;
    BTNode* parent_node = NULL;

    while (current_node) {
        if (data < current_node->data) {
            parent_node = current_node;
            current_node = current_node->left;
            last_side = LEFT;
        } else if (data > current_node->data) {
            parent_node = current_node;
            current_node = current_node->right;
            last_side = RIGHT;
        } else {
            found = 1;
            break;
        }
    }

    if (!found) {
        return 0;
    }

    BTNode* substitution;

    if (current_node->left) {
        if (current_node->right) {  
            /* O nodo a ser removido tem dois filhos */

            // Substituir o nodo atual pelo menor nodo da subárvore direita

            BTNode* smallest_node = current_node->right;

            if (!smallest_node->left) {
                // O menor nodo da subárvore direita é o filho direito do nodo atual
                
                smallest_node->right = current_node->right;
            } else {
                BTNode* smallest_node_parent = current_node;
                
                while (smallest_node->left) {
                    smallest_node_parent = smallest_node;
                    smallest_node = smallest_node->left;
                }

                smallest_node_parent->left = smallest_node->right;
            }

            substitution = smallest_node;
            smallest_node->left = current_node->left;
        } else {                      
            /* O nodo a ser removido tem spenas filho esquerdo */
            substitution = current_node->left;
        }
    } else if (current_node->right) {
        /* O nodo a ser removido tem apenas filho direito */
        substitution = current_node->right;
    } else {                          
        /* O nodo a ser removido é nodo folha */
        // (Nodo raiz && Nodo folha) => A árvore só tem um nodo
        substitution = NULL;
    }

    if (!parent_node) {
        tree->root = substitution;
    } else {
        switch (last_side) {
            case LEFT: {
                parent_node->left = substitution;
                break;
            }

            case RIGHT: {
                parent_node->right = substitution;
                break;
            }
        }
    }

    free(current_node);
    return 1;
}

// Função interna para BTEmpty()
// Não exposta no header
int _BTEmpty_free(BTNode* node) {
    free(node);
    return 0;
}

void BTEmpty(BinaryTree* tree) {
    BTForEach(*tree, TRAVERSAL_POST, LEFT, _BTEmpty_free);
    tree->root = NULL;
}
