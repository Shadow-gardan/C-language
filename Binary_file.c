#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fs, *ft;
    int ch;

    fs = fopen("pr1.exe", "rb");
    if (fs == NULL) {
        puts("Cannot open source file");
        exit(1);
    }

    ft = fopen("newpr1.exe", "wb");
    if (ft == NULL) {
        puts("Cannot open target file");
        fclose(fs);
        exit(1);
    }

    while ((ch = fgetc(fs)) != EOF) {
        fputc(ch, ft);
    }

    fclose(fs);
    fclose(ft);

    return 0;
}

