#pragma once


typedef int StackData;

typedef struct Stack {
    StackData* data;
    int limit;
    int top;
} Stack;


// Criar uma pilha vazia
Stack StackCreate(StackData* data, int limit);

// Verificar se a pilha está vazia
int StackIsEmpty(Stack stack);

// Verificar se a pilha está cheia
int StackIsFull(Stack stack);

// Inserir elemento no topo da pilha
int StackPush(Stack* stack, StackData element);

// Remover elemento do topo da pilha e retornar seu valor por parâmetro
// Retorna 0 se a pilha estiver vazia e 1 caso contrário
int StackPop(Stack* stack, StackData* element);

// Consultar elemento no topo da pilha
// Retorna 0 se a pilha estiver vazia e 1 caso contrário
int StackPeek(Stack stack, StackData* element);

// Retorna 1 caso as pilhas sejam iguais e 0 caso contrário
int StackCompare(Stack s1, Stack s2);
