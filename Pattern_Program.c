#include <stdio.h>
#include <conio.h>
int main() {
    
	int i,j,k,l,sp;
	sp=20;
	for(i=1,k=1;i<10;i++){
		for(l=1;l<=sp;l++){
			printf(" ");
		
		}
			sp -=4;
		
		for(j=1;j<=i;k++,j++){
			printf("%d ",k);
		}
		printf("\n");
	}
		for(i=1,k=1;i<10;i++){
		for(l=1;l<=sp;l++){
			printf(" ");
		
		}
			sp +=3;
		
		for(j=1;j<=i;k++,j++){
			printf("%d ",k);
		}
		printf("\n");
	}
	printf("\n\n\n\n\n\n Press any key for to exit");
    return 0;
}

