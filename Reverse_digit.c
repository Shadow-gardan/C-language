#include <stdio.h>

int main() {
	int a,n,b;
	long int revnum = 0;
	
	printf("Enter the Five digite(less than 32767): ");
	scanf("%d",&n);
	
	a = n%10;
	n = n/10;
	revnum = revnum+a*10000;
	
	a = n%10;
	n = n/10;
	revnum = revnum+a*1000;
	
	a = n%10;
	n = n/10;
	revnum = revnum+a*100;
	
	a = n%10;
	n = n/10;
	revnum = revnum+a*10;
	
	a = n%10;
	n = n/10;
	revnum = revnum+a;
	
	printf("The reverse number is %ld :",revnum);
	
	
    return 0;
}

