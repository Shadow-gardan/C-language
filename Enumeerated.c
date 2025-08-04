// Enumerated data type  given you an opporturinity to invent  your own data type and define 
// what values the variable of this data type can take.  

#include<stdio.h>
#include<string.h>

int main(){
	
	
	enum emp_dept{
		assembly, manufacturing, accounts, stores
	};
	
	struct employee{
		char name[35];
		int age;
		float bs;
		enum emp_dept department;
	};
	
	struct employee e;
	
	strcpy (e.name,"Loman");
	e.age = 28;
	e.bs = 3245.45;
	e.department = stores;
	
	
	printf("Name = %s\n",e.name);
	printf("Age = %d\n",e.age);
	printf("BS = %f\n",e.bs);
	printf("Depth = %d\n",e.department);
	
	if(e.department == accounts){
		printf("%s is an accountant \n",e.name);
	}
	else{
		printf("%s is not a accountant \n",e.name);
	}
	
	return 0;
}
