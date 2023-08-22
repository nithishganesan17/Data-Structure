#include <stdio.h>

int main() {
	printf("nithish 192221138");
    int numbers[] = {5, 2, 8, 1, 9, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Odd values: ");
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 != 0) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");

    printf("Even values: ");
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 == 0) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");

    return 0;
}

