#include <stdio.h>
#include <string.h>
int main() {
	 
	int goal;
	
	
		printf("Enter the number of Goals scored : ");
		scanf("%d",&goal);
		
		if(goal <= 5){
			goto sos;
		}
		
		else{
			printf("It About the Finesh the game");
			return;
		}
	
		sos:
		  printf("To error");	
    return 0;
}

