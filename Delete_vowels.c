#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[80], str1[80];
    char *s, *p;

    printf("Enter a sentence (max 79 characters): \n");
    fgets(str, sizeof(str), stdin);

    s = str;
    p = str1;

    while (*s) {
        char ch = *s;

        // Convert character to lowercase for easier comparison
        if (!(tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' ||
              tolower(ch) == 'o' || tolower(ch) == 'u')) {
            *p = ch;
            p++;
        }
        s++;
    }

    *p = '\0';  // Null-terminate the new string

    printf("String after deleting vowels: %s\n", str1);
    return 0;
}

