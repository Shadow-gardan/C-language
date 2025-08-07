#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char s[80];

    fp = fopen("poem.txt", "w");
    if (fp == NULL) {
        puts("Cannot open file");
        exit(1);
    }

    printf("Enter a few lines of text (press Enter on an empty line to stop):\n");
    while (1) {
        fgets(s, sizeof(s), stdin);
        
        // Stop if only Enter is pressed
        if (strcmp(s, "\n") == 0)
            break;

        fputs(s, fp);
    }

    fclose(fp);
    return 0;
}

