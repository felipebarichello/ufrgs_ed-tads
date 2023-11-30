#include <stdlib.h>
#include <stdio.h>
#include "bt.h"


BTNode* BTNewNode(BTData data) {
    BTNode* new_node = (BTNode*) malloc(sizeof(BTNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
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

BTNode* BTInsert(BinaryTree* tree, BTData data) {
    if (!tree) {
        return NULL;
    }

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

void BTPrint(BTNode* head) {
    // printf("[\n");

    // for (BTNode* current_node = head; current_node; current_node = current_node->next) {
    //     printf("\t{\n\t\tCodigo: %d,\n\t\tNome: %s,\n\t\tPreco: %.2f\n\t}\n", current_node->data.code, current_node->data.name, current_node->data.price);
    // }

    // printf("]\n");
}

int BTRemove(BTNode** head, int code) {
    // if (!*head) {
    //     return 0;
    // }

    // if ((*head)->data.code == code) {
    //     BTNode* next_node = (*head)->next;

    //     if (next_node) {
    //         next_node->prev = NULL;
    //     }

    //     free(*head);
    //     *head = next_node;

    //     return 1;
    // }

    // BTNode* current_node = *head;

    // while (current_node) {
    //     if (current_node->data.code == code) {
    //         current_node->prev->next = current_node->next;
    //         current_node->next->prev = current_node->prev;
    //         free(current_node);

    //         return 1;
    //     }

    //     current_node = current_node->next;
    // }

    // return 0;
}

void BTDestroy(BTNode** head) {
    // BTNode* current_node = *head;
    // *head = NULL;

    // while (current_node) {
    //     BTNode* next_node = current_node->next;

    //     if (!next_node) {
    //         break;
    //     }

    //     free(current_node);
    //     current_node = next_node;
    // }
}
