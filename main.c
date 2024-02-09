#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initialize_stack(Stack *stack) {
    stack->top = NULL;
}

int is_empty(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, int element) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow: Cannot pop element from empty stack.\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

int peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

int main() {
    Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Top element after popping: %d\n", peek(&stack));

    return 0;
}

