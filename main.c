#include <stdio.h>

#define MAX_SIZE 100

struct StaticStack {
    int elements[MAX_SIZE];
    int top;
};

void InitializeStack(struct StaticStack *stack) {
    stack->top = -1;
}

int IsFull(struct StaticStack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int IsEmpty(struct StaticStack *stack) {
    return stack->top == -1;
}

void PushElement(struct StaticStack *stack, int element) {
    if (IsFull(stack)) {
        printf("Erro: A pilha está cheia\n");
    } else {
        stack->elements[++stack->top] = element;
    }
}

int PopElement(struct StaticStack *stack) {
    if (IsEmpty(stack)) {
        printf("Erro: A pilha está vazia\n");
        return -1;  // Valor de erro
    } else {
        return stack->elements[stack->top--];
    }
}

int TopElement(struct StaticStack *stack) {
    if (IsEmpty(stack)) {
        printf("Erro: A pilha está vazia\n");
        return -1;  // Valor de erro
    } else {
        return stack->elements[stack->top];
    }
}

int main() {
    struct StaticStack stack;
    InitializeStack(&stack);

    PushElement(&stack, 10);
    PushElement(&stack, 20);
    PushElement(&stack, 30);

    printf("Elemento no topo da pilha: %d\n", TopElement(&stack));

    printf("Elemento removido: %d\n", PopElement(&stack));
    printf("Elemento removido: %d\n", PopElement(&stack));

    printf("Elemento no topo após a remoção: %d\n", TopElement(&stack));

    return 0;
}
