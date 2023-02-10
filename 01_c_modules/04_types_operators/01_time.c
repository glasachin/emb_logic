#include<stdio.h>
int main()
{
	int sec_in,days,hrs,min,sec;
	printf("Enter number of seconds: ");
	scanf("%d",&sec_in);
	min = sec_in/60;
	sec = sec_in - min*60;
	hrs = min/60;
	min = min - hrs*60;
	days = hrs/24;
	hrs = hrs - days*24;

	printf("%d Secods = %d Days:%d Hrs:%d minuts:%d seconds\n",sec_in,days,hrs,min,sec);
	return 0;
}
