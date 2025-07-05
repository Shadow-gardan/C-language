#include <stdio.h>
#include <string.h>
int main() {
	 char c;
	 
	 printf("Enter the character A-C : ");
	 scanf("%c",&c);
	 
	 switch(c){
	 	case 'A':
	 		printf("Introvert");
	 		break;
		case 'B':
	 		printf("Extrovert");
	 		break;	 
		case 'C':
	 		printf("Anitrovert");
	 		break;	 
			 
		default :
			 printf("Invalid value");	 		
	 }
	 
	 return 0;
}

