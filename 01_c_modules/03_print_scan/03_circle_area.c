#include<stdio.h>
int main()
{
	float rad = 6;
	float par,area;
	par = 2*3.14*rad;
	area = 3.14*rad*rad;
	printf("Parameter and Area of Circle having radius as %f inches are %0.2f inches and %0.2f inches^2\n",rad,par,area);

	printf("Enter the radius of other circle in inches: ");
	scanf("%f", &rad);
	par = 2*3.14*rad;
	area = 3.14*rad*rad;
	printf("Parameter and Area of Circle having radius as %0.2f inches are %0.2f inches and %0.2f inches^2\n",rad,par,area);

	return 0;
}
