#include <stdio.h>
#include <stdlib.h>


struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}


int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

int isFull(struct Queue* queue) {
    return queue->size == queue->capacity;
}


void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}
 
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}


struct Stack {
    struct Queue* q1;
    struct Queue* q2;
};


struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->q1 = createQueue(100);  
    stack->q2 = createQueue(100);
    return stack;
}

void push(struct Stack* stack, int item) {
    if (isEmpty(stack->q1)) {
        enqueue(stack->q1, item);
    } else {
        while (!isEmpty(stack->q1)) {
            enqueue(stack->q2, dequeue(stack->q1));
        }
        enqueue(stack->q1, item);
        while (!isEmpty(stack->q2)) {
            enqueue(stack->q1, dequeue(stack->q2));
        }
    }
}

int pop(struct Stack* stack) {
    if (isEmpty(stack->q1)) {
        return -1;
    }
    return dequeue(stack->q1);
}

int main() {
	printf("nithish 192221138\n");
	
    struct Stack* stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("%d\n", pop(stack));  
    printf("%d\n", pop(stack));  
    printf("%d\n", pop(stack));  

    return 0;
}
