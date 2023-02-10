#include<stdio.h>
int main()
{
	int in_days;
	int yrs, months, days;
	printf("Enter number of days: ");
	scanf("%d",&in_days);
	months = in_days/30;
	days = in_days - months*30;
	yrs = months/12;
	months -= yrs*12;
	printf("%d Days = %d yrs, %d months, %d days\n",in_days,yrs,months,days);
	return 0;
}
