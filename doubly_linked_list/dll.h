#pragma once

typedef struct DLLData {
    int code;
    char name[50];
    float price;
} DLLData;

typedef struct DLLNode {
    struct DLLNode* next;
    struct DLLNode* prev;
    DLLData data;
} DLLNode;

// Inserir (em ordem crescente de código)
// Retorna o endereço do novo nó
DLLNode* DLLInsert(DLLNode** head, DLLData data);

// Imprimir
void DLLPrint(DLLNode* head);

// Imprimir reverso
void DLLPrintReverse(DLLNode* head);

// Imprimir
// Retorna 1 se encontrou o produto, 0 caso contrário
int DLLRemove(DLLNode** head, int code);

// Destruir
// Seta *head para NULL
void DLLDestroy(DLLNode** head);
