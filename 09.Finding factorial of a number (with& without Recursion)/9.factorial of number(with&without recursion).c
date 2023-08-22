#include <stdio.h>

int factorial_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial_recursive(n - 1);
    }
}

int main() {
    int num;
    printf("Nithish 192221138\n");
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial: %d\n", factorial_recursive(num));
    return 0;
}

