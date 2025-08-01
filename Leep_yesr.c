#include<stdio.h>
int main(){
	
	int i,n;
	printf("How many time to check: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		leeps();
	}

    return 0;
}

void leeps(){
	    int num;
    printf("Enter the number: ");
    scanf("%d",&num);

    char*leep[] = {"It was a Leep year" , "It was not a Leep year"};

    printf(leep[num % 4 && num % 100]);
    printf("\n");
}
