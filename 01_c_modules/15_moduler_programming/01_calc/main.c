#include "operations.c"
int main()
{
	int a, b, c;
	char op;
	printf("Enter any two numbers: ");
	scanf("%d%d",&a,&b);
	getchar();
	printf("Enter any operation operator: +, -, *, /\n");
	scanf("%c",&op);
	if(op == '+')
		printf("Addition of numbers is %d\n",add(a,b));
	else if(op == '-')
		printf("Subtraction of numbers is %d\n",sub(a,b));
	else if(op == '*')
		printf("Multiplication of numbers is %d\n",mul(a,b));
	else if(op == '/')
		printf("Division of numbers is %d\n",div(a,b));
	else
		printf("Wrong Choice!\n");
	

	return 0;
}
