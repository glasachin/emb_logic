#include<stdio.h>

int main()
{
	int a = 1;
	char *p = &a;
	char b[4] = {1,1,0,0};
	int *q = b;
	printf("%d\n",p[0]);
	p[1]=1;
	printf("%d\n",a);
	
	printf("%d\n",q[0]);

	return 0;
}
