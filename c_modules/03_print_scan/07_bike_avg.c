#include<stdio.h>
int main()
{
	int tr_dis;
	float ltr,avg;
	printf("Please Enter Travelled Distance (Km): ");
	scanf("%d",&tr_dis);
	printf("Petrol Consumed (Liters): ");
	scanf("%f",&ltr);
	avg = tr_dis/ltr;
	printf("Bike is giving an average of %0.2f Km/ltr\n",avg);
	return 0;
}
