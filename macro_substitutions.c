#include<stdio.h>
int main(){

    int i = 4;
    #ifdef DEF
        i*=4;

    #else
        printf("\n %d",i);

    #endif

    return 0;
}
