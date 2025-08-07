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

    while (fgets(s,79,fp) != NULL) {
        printf("%s",s);
    }

    printf("\n");
    fclose(fp);
    return 0;
}
