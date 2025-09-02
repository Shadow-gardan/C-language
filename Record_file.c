#include<stdio.h>

int main(){
    FILE *fp;
    char another = 'Y';
    struct emp{
        char name[40];
        int age;
        float bs;
    };
    struct emp e;
    fp = fopen("Employee.dat","w");

    if(fp == NULL){
        puts("cannot open the file");
        exit(1);
    }

    while(another == 'Y'){
        printf("\n\nEnter the name , age and basic salary\n");
        scanf("%s %d %f", e.name,&e.age,&e.bs);
        fprintf(fp,"%s %d %f\n",e.name,e.age,e.bs);

        printf("Add another record(Y/N)");
        fflush(stdin);
        another = getche();
    }

    fclose(fp);
    return 0;
}