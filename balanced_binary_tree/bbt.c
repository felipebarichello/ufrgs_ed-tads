#include <stdlib.h>
#include <stdio.h>
#include "bbt.h"


BBTNode* BBTNewNode(BBTData data) {
    BBTNode* new_node = (BBTNode*) malloc(sizeof(BBTNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

BalancedBinaryTree BBTCreate() {
    return (BalancedBinaryTree) { NULL };
}

BalancedBinaryTree BBTFromNode(BBTNode* root) {
    return (BalancedBinaryTree) { root };
}

BBTData BBTIsEmpty(BalancedBinaryTree tree) {
    return !tree.root;
}

BBTNode* BBTInsertOrdered(BalancedBinaryTree* tree, BBTData data) {
    if (BBTIsEmpty(*tree)) {
        tree->root = BBTNewNode(data);
        return tree->root;
    }

    BBTNode* current_node = tree->root;

    for (;;) {
        if (data < current_node->data) {
            if (!current_node->left) {
                current_node->left = BBTNewNode(data);
                return current_node->left;
            }

            current_node = current_node->left;
        } else if (data > current_node->data) {
            if (!current_node->right) {
                current_node->right = BBTNewNode(data);
                return current_node->right;
            }

            current_node = current_node->right;
        } else {
            return NULL;
        }
    }
}

BBTNode* BBTSearch(BalancedBinaryTree tree, BBTData data) {
    BBTNode* current_node = tree.root;

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

// Função recursiva interna para BBTForEach()
// Não exposta no header
int _BBTForEach(BBTNode* node, enum BBTTraversal traversal, enum BBTSide order, int (*operation)(BBTNode* node)) {
    if (!node) {
        return 0;
    }

    BBTNode* first_child;
    BBTNode* second_child;

    switch (order) {
        case BBT_LEFT: {
            first_child = node->left;
            second_child = node->right;
            break;
        }

        case BBT_RIGHT: {
            first_child = node->right;
            second_child = node->left;
            break;
        }
    }

    if (traversal == BBT_TRAVERSAL_PRE)
        if (operation(node))
            return 1;

    if (_BBTForEach(first_child, traversal, order, operation))
        return 1;

    if (traversal == BBT_TRAVERSAL_IN)
        if (operation(node))
            return 1;

    if (_BBTForEach(second_child, traversal, order, operation))
        return 1;

    if (traversal == BBT_TRAVERSAL_POST)
        if (operation(node))
            return 1;
    
    return 0;
}

int BBTForEach(BalancedBinaryTree tree, enum BBTTraversal traversal, enum BBTSide order, int (*operation)(BBTNode* node)) {
    return _BBTForEach(tree.root, traversal, order, operation);
}

// Função interna para BBTPrintList()
// Não exposta no header
int _BBTPrintNode_print(BBTNode* node) {
    printf("%d ", node->data);
    return 0;
}

void BBTPrintList(BalancedBinaryTree tree, enum BBTTraversal traversal, enum BBTSide order) {
    printf("[ ");
    _BBTForEach(tree.root, traversal, order, _BBTPrintNode_print);
    printf("]\n");
}

int BBTRemove(BalancedBinaryTree* tree, BBTData data) {
    if (BBTIsEmpty(*tree)) {
        return 0;
    }

    int found = 0;
    enum BBTSide last_side;
    BBTNode* current_node = tree->root;
    BBTNode* parent_node = NULL;

    while (current_node) {
        if (data < current_node->data) {
            parent_node = current_node;
            current_node = current_node->left;
            last_side = BBT_LEFT;
        } else if (data > current_node->data) {
            parent_node = current_node;
            current_node = current_node->right;
            last_side = BBT_RIGHT;
        } else {
            found = 1;
            break;
        }
    }

    if (!found) {
        return 0;
    }

    BBTNode* suBBTitution;

    if (current_node->left) {
        if (current_node->right) {  
            /* O nodo a ser removido tem dois filhos */

            // SuBBTituir o nodo atual pelo menor nodo da subárvore direita

            BBTNode* smallest_node = current_node->right;

            if (!smallest_node->left) {
                // O menor nodo da subárvore direita é o filho direito do nodo atual
                
                smallest_node->right = current_node->right;
            } else {
                BBTNode* smallest_node_parent = current_node;
                
                while (smallest_node->left) {
                    smallest_node_parent = smallest_node;
                    smallest_node = smallest_node->left;
                }

                smallest_node_parent->left = smallest_node->right;
            }

            suBBTitution = smallest_node;
            smallest_node->left = current_node->left;
        } else {                      
            /* O nodo a ser removido tem spenas filho esquerdo */
            suBBTitution = current_node->left;
        }
    } else if (current_node->right) {
        /* O nodo a ser removido tem apenas filho direito */
        suBBTitution = current_node->right;
    } else {                          
        /* O nodo a ser removido é nodo folha */
        // (Nodo raiz && Nodo folha) => A árvore só tem um nodo
        suBBTitution = NULL;
    }

    if (!parent_node) {
        tree->root = suBBTitution;
    } else {
        switch (last_side) {
            case BBT_LEFT: {
                parent_node->left = suBBTitution;
                break;
            }

            case BBT_RIGHT: {
                parent_node->right = suBBTitution;
                break;
            }
        }
    }

    free(current_node);
    return 1;
}

// Função interna para BBTEmpty()
// Não exposta no header
int _BBTEmpty_free(BBTNode* node) {
    free(node);
    return 0;
}

void BBTEmpty(BalancedBinaryTree* tree) {
    BBTForEach(*tree, BBT_TRAVERSAL_POST, BBT_LEFT, _BBTEmpty_free);
    tree->root = NULL;
}
