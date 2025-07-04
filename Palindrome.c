#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) return false;

    int original = x;
    int reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        if (reversed > (2147483647 - digit) / 10) {
            return false;
        }
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return original == reversed;
}

int main() {
    int x;
	
	    printf("Enter an integer: ");
	    scanf("%d", &x);
	
	    if (isPalindrome(x)) {
	        printf("true\n");
	    } else {
	        printf("false\n");
	    }
    return 0;
}

