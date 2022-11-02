#include<stdio.h>
#include<math.h>
int main()
{
	float rad;
	float volume;
	printf("Enter the radius of the sphere: ");
	scanf("%f",&rad);
	volume = 3.14*pow(rad,3);
	printf("Volume = %0.2funits\n",volume);
	return 0;
}
