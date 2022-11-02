#include<stdio.h>
#include<math.h>
int main()
{
	float  x1, y1;
	float x2, y2;
	float dist;
	printf("Enter 1st Point Pairs (x1,y1): ");
	scanf("%f%f",&x1,&y1);
	printf("Enter 2nd Point Pairs (x2,y2): ");
	scanf("%f%f",&x2,&y2);
	dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	printf("Distance between two points (%0.2f,%0.2f) and (%0.2f,%0.2f) is %0.4f.\n",x1,y1,x2,y2,dist); 
	return 0;
}
