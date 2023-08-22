#include <stdio.h>
#include <stdlib.h>


struct Stack {
    int top;
    unsigned capacity;
    int* array;
};


struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}


void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}


int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->array[stack->top--];
}


struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};


struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}


void enqueue(struct Queue* queue, int item) {
    while (!isEmpty(queue->stack1)) {
        push(queue->stack2, pop(queue->stack1));
    }
    push(queue->stack1, item);
    while (!isEmpty(queue->stack2)) {
        push(queue->stack1, pop(queue->stack2));
    }
}


int dequeue(struct Queue* queue) {
    if (isEmpty(queue->stack1)) {
        return -1;
    }
    return pop(queue->stack1);
}

int main() {
	printf("nithish \n 192221138\n");
    struct Queue* queue = createQueue(100); 
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("%d\n", dequeue(queue));  
    printf("%d\n", dequeue(queue));  
    printf("%d\n", dequeue(queue));  

    return 0;
}
