#include<stdio.h>
int main()
{
	int in;
	char month[10];
	char jan[]="January",feb[]="Februray",mar[]="March";
	printf("Enter any number between 1-12: ");
	scanf("%d",in);
	month = in==1?jan:NULL;
	month = in==2?feb:NULL;

	printf("%s\n",month);

	return 0;
}
