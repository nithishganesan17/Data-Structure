#include <stdio.h>

int main() {
	printf("nithish 192221138");
    int numbers[] = {5, 2, 8, 1, 9, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int elementToFind = 8;
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (numbers[i] == elementToFind) {
            printf("Element %d found at index %d\n", elementToFind, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", elementToFind);
    }

    return 0;
}

