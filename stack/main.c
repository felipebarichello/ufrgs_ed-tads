#include "stdio.h"
#include "stack.h"


int main() {
    StackData data[64];

    Stack p1 = StackCreate(data,      3);
    StackPush(&p1, 1);
    StackPush(&p1, 2);
    StackPush(&p1, 3);
    StackPush(&p1, 4);

    Stack p2 = StackCreate(data + 4,  3);
    StackPush(&p2, 2);
    StackPush(&p2, 3);
    StackPush(&p2, 4);

    Stack p3 = StackCreate(data + 8,  3);
    StackPush(&p3, 4);
    StackPush(&p3, 3);
    StackPush(&p3, 2);
    StackPush(&p3, 1);

    Stack p4 = StackCreate(data + 12, 3);
    StackPush(&p4, 4);
    StackPush(&p4, 3);
    StackPush(&p4, 2);
    StackPush(&p4, 1);

    printf("P1 e P2 sao %s\n", StackCompare(p1, p2) ? "IGUAIS" : "DIFERENTES");
    printf("P3 e P4 sao %s\n", StackCompare(p3, p4) ? "IGUAIS" : "DIFERENTES");
}
