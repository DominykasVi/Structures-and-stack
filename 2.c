#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int *value_pointer;
	int size;
} Stack;

void initStack(Stack * stack){
    stack->value_pointer = malloc(sizeof(int)*1);
    *(stack->value_pointer) = 0;
    stack->size = 0;
}

void printStack(Stack *stack){
    //printf("%d", stack->size);
    if (stack->size == 0){
        printf("Stack is empty");
    }
    for(int i = stack->size; i > 0 ; --i){
        printf("%d\n", *(stack->value_pointer + i - 1));
    }
}

int getStackSize(Stack * stack){
    return stack->size;
}

void push(Stack *stack, int value){
    stack->size += 1;
    stack->value_pointer = (int *) realloc(stack->value_pointer,sizeof(int) * stack->size);
    *(stack->value_pointer + stack->size - 1) = value;
}

int top(Stack * stack){
    if (getStackSize(stack) == 0){
        return 0;
    }
    return *(stack->value_pointer+getStackSize(stack)-1);
}

int pop(Stack * stack){
    int var  = top(stack);
    stack->size -= 1;
    stack->value_pointer = (int *) realloc(stack->value_pointer,sizeof(int) * stack->size);
    return var;
}

void destroyStack(Stack * stack){
    stack->value_pointer = (int *) realloc(stack->value_pointer,0);
    stack->size = 0;
}

int main() {
    Stack stack;
    initStack(&stack);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);
    printStack(&stack);
    printf("\n\n");
    //printf("%d\n\n\n", getStackSize(&stack));
    //printf("%d\n", top(&stack));
    int var = pop(&stack);
    printf("poped: %d\n", var);
    printStack(&stack);
    destroyStack(&stack);
    printf("%p", stack.value_pointer);


    return 0;
}
