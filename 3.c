#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Point {
    double x;
    double y;
} Point;

Point createPoint(double x, double y){
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

typedef struct Stack {
    Point *point_pointer;
    int size;
} Stack;

int getStackSize(Stack * stack){
    return stack->size;
}

void push(Stack *stack, Point value){
    stack->size += 1;
    stack->point_pointer = (Point *) realloc(stack->point_pointer,sizeof(Point) * stack->size);
    *(stack->point_pointer + stack->size - 1) = value;
}

Point top(Stack * stack){
    if (getStackSize(stack) == 0){
        return createPoint(0,0);
    }
    return *(stack->point_pointer+getStackSize(stack)-1);
}

Point pop(Stack * stack){
    Point var  = top(stack);
    stack->size -= 1;
    stack->point_pointer = (Point *) realloc(stack->point_pointer,sizeof(Point) * stack->size);
    return var;
}

void initStack(Stack * stack){
    stack->point_pointer = malloc(sizeof(struct Point)*1);
    *(stack->point_pointer) = createPoint(0, 0);
    stack->size = 0;
}

void printPoint(Point p){
    printf("(%.5lf, %.5lf)", p.x, p.y);
}

double getDistance(Point a, Point b){
    double distance;
    distance = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
    return distance;
}

void printStack(Stack *stack){
    if (stack->size == 0){
        printf("Stack is empty");
    }
    Point p = createPoint(0, 0);
    for(int i = stack->size; i > 0 ; --i){
        printPoint(*(stack->point_pointer + i - 1));
        printf(" distance to ");
        printPoint(p);
        printf(": %lf\n", getDistance(*(stack->point_pointer + i - 1), p));
    }
}

void destroyStack(Stack * stack){
    stack->point_pointer = (Point *) realloc(stack->point_pointer,0);
    stack->size = 0;
}

int main() {
    Stack stack;
    Point p1 = createPoint(5, 10);
    Point p2 = createPoint(15, 20);
    Point p3 = createPoint(1, 5);
    Point p4 = createPoint(2, 6);
    Point p5 = createPoint(3, 4);
    initStack(&stack);
    push(&stack, p1);
    push(&stack, p2);
    push(&stack, p3);
    push(&stack, p4);
    push(&stack, p5);
    printStack(&stack);

    p1 = pop(&stack);
    printf("\n");
    printPoint(p1);

    p2 = pop(&stack);
    printf("\n\n");
    printStack(&stack);
    destroyStack(&stack);
    printStack(&stack);
    return 0;
}