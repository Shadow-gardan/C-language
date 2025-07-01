#include <stdio.h>

void target(int num[], int size, int targets) {
    int i, a;
    for(i = 0; i < size - 1; i++) {
        a = num[i] + num[i+1];
        if(a == targets) {
            printf("Target was found\n");
            printf("[%d, %d]\n", num[i], num[i+1]);
            return;  // exit once found
        }
    }
    printf("Target not found\n");
}

int main() {
    int num[5];
    int i, size = 5;
    int targets;

    // take user input
    printf("Enter 5 values:\n");
    for(i = 0; i < size; i++) {
        printf("%d: ", i);
        scanf("%d", &num[i]);
    }

    printf("Enter the target: ");
    scanf("%d", &targets);

    // call target function
    target(num, size, targets);

    return 0;
}

