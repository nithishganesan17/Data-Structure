#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int reversed = 0;
    
    while (x != 0) {
        // Handle overflow and underflow
        if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10) {
            return 0;
        }
        
        // Extract the last digit of x
        int digit = x % 10;
        
        
        reversed = reversed * 10 + digit;
        
        x /= 10;
    }
    
    return reversed;
}

int main() {
	 printf("nithish 192221138\n");
	
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    int reversed = reverse(num);
    
    printf("Original: %d\n", num);
    printf("Reversed: %d\n", reversed);
    
    return 0;
}

