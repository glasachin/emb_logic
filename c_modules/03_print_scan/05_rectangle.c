#include<stdio.h>
int main()
{
	int h = 7, w = 5;
	int par;
	int area;
	par = 2*(h+w);
	area = h*w;
	printf("Parameter and Area of Rectangle with Height of %d and Width of %d are %d inches and %d inches^2 respecively.\n",h,w,par,area);

	return 0;
}
