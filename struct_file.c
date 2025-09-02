#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    struct emp {
        char name[40];
        int age;
        float bs;
    };
    struct emp e;

    fp = fopen("Employee.dat", "r");  // Open in text mode

    if (fp == NULL) {
        puts("Cannot open the file");
        exit(1);
    }

    while (fscanf(fp, "%s %d %f", e.name, &e.age, &e.bs) != EOF) {
        printf("%s %d %.2f\n", e.name, e.age, e.bs);
    }

    fclose(fp);
    return 0;
}

