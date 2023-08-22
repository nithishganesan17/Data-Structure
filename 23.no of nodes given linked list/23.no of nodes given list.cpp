#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
	printf("nithish 192221138");
    struct Node* head = NULL;

    int nodeCount = countNodes(head);
    printf("Number of nodes in the linked list: %d\n", nodeCount);
    
    return 0;
}
