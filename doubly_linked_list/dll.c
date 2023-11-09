#include "dll.h"
#include "stdlib.h"
#include "stdio.h"


DLLNode* DLLInsert(DLLNode** head, DLLData data) {
    DLLNode* new_node = (DLLNode*) malloc(sizeof(DLLNode));
    new_node->data = data;

    if (!*head) {
        new_node->next = NULL;
        new_node->prev = NULL;
        *head = new_node;

        return new_node;
    }

    if ((*head)->data.code > data.code) {
        new_node->next = *head;
        (*head)->prev = new_node;
        new_node->prev = NULL;
        *head = new_node;

        return new_node;
    }

    DLLNode* prev_node = *head;
    DLLNode* next_node = (*head)->next;

    while (next_node && next_node->data.code < data.code) {
        prev_node = next_node;
        next_node = next_node->next;
    }
    
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (!next_node) {
        new_node->next = NULL;
    } else {
        new_node->next = next_node;
        next_node->prev = new_node;
    }

    return new_node;
}

void DLLPrint(DLLNode* head) {
    printf("[\n");

    for (DLLNode* current_node = head; current_node; current_node = current_node->next) {
        printf("\t{\n\t\tCodigo: %d,\n\t\tNome: %s,\n\t\tPreco: %.2f\n\t}\n", current_node->data.code, current_node->data.name, current_node->data.price);
    }

    printf("]\n");
}

void DLLPrintReverse(DLLNode* head) {
    printf("[\n");

    DLLNode* current_node = head;

    if (head) {
        while (current_node->next) {
            current_node = current_node->next;
        }
    }

    while (current_node) {
        printf("\t{\n\t\tCodigo: %d,\n\t\tNome: %s,\n\t\tPreco: %.2f\n\t}\n", current_node->data.code, current_node->data.name, current_node->data.price);
        current_node = current_node->prev;
    }

    printf("]\n");
}

int DLLRemove(DLLNode** head, int code) {
    if (!*head) {
        return 0;
    }

    if ((*head)->data.code == code) {
        DLLNode* next_node = (*head)->next;

        if (next_node) {
            next_node->prev = NULL;
        }

        free(*head);
        *head = next_node;

        return 1;
    }

    DLLNode* current_node = *head;

    while (current_node) {
        if (current_node->data.code == code) {
            current_node->prev->next = current_node->next;
            current_node->next->prev = current_node->prev;
            free(current_node);

            return 1;
        }

        current_node = current_node->next;
    }

    return 0;
}

void DLLDestroy(DLLNode** head) {
    DLLNode* current_node = *head;
    *head = NULL;

    while (current_node) {
        DLLNode* next_node = current_node->next;

        if (!next_node) {
            break;
        }

        free(current_node);
        current_node = next_node;
    }
}
