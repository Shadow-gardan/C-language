#include<stdio.h>
int main(){
	
	union a{
		short int i;
		char ch[2];
	};
	
	union a key;
	
	key.i = 231;
	printf("key.i = %d\n",key.i);
	printf("key.ch[0] = %d\n",key.ch[0]);
	printf("key.ch[1] = %d\n",key.ch[1]);
	
	printf("\n\n");
	
	key.ch[0] = 50;
	printf("key.i = %d\n",key.i);
	printf("key.ch[0] = %d\n",key.ch[0]);
	printf("key.ch[1] = %d\n",key.ch[1]);
	
	return 0;
}
