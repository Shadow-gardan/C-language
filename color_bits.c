// Program to display color names based on bitwise representation of an integer
#include <stdio.h>

int main(){
    int color;

    // Prompt user for input
    printf("Enter the Number\n");
    scanf("%d", &color);

    // Display the colors represented by the bits in the input number
    printf("Color represented are :\n");
    if (color & 1) { // Bit 0: Red
        printf("Red\n");
    }
    if (color & 2) { // Bit 1: Green
        printf("Green\n");
    }
    if (color & 4) { // Bit 2: Blue
        printf("Blue\n");
    }
    if (color & 8) { // Bit 3: Yellow
        printf("Yellow\n");
    }
    if (color & 16) { // Bit 4: Cyan
        printf("Cyan\n");
    }
    if (color & 32) { // Bit 5: Magenta
        printf("Magenta\n");
    }
    if (color & 64) { // Bit 6: White
        printf("White\n");
    }   
    if (color & 128) { // Bit 7: Black
        printf("Black\n");
    }

    return 0;
}