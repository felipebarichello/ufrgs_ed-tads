#include <stdlib.h>
#include "stack.h"


Stack StackCreate(StackData* data, int limit) {
    return (Stack) {
        data,
        limit,
        -1
    };
}

int StackIsEmpty(Stack stack) {
    return stack.top == -1;
}

int StackIsFull(Stack stack) {
    return stack.top == stack.limit;
}

int StackPush(Stack* stack, StackData element) {
    if (StackIsFull(*stack)) {
        return 0;
    }

    stack->data[++stack->top] = element;

    return 1;
}

int StackPop(Stack* stack, StackData* element) {
    if (StackIsEmpty(*stack)) {
        return 0;
    }

    *element = stack->data[stack->top--];

    return 1;
}

int StackPeek(Stack stack, StackData* element) {
    if (StackIsEmpty(stack)) {
        return 0;
    }

    *element = stack.data[stack.top];

    return 1;
}

int StackCompare(Stack s1, Stack s2) {
    // Se as pilhas não tiverem o mesmo tamanho, elas não são iguais
    if (s1.top != s2.top) {
        return 0;
    }

    for (int i = 0; i <= s1.top; i++) {
        if (s1.data[i] != s2.data[i]) {
            return 0;
        }
    }

    return 1;
}
