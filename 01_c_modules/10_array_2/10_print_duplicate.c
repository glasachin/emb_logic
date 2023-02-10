#include<stdio.h>
#define N 10
int main()
{
	int a[N],u[N],u_n = 0,o[N],occ[N] = {0};
	int i, j, d_c=0;
	printf("Enter %d array elements: ",N);
	for(i = 0; i < N; i++)
	{
		scanf("%d",&a[i]);
	}
	//----First Find Uniques---------
	j = 0;
    u[0] = a[0];
    u_n = 1; //no. of unique numbers
    for(i = 1; i < N; i++)
    {
        for(j = 0; j < u_n; j++)
        {
            if(a[i] == u[j])
                break;
        }
        if( j == u_n)
        {
            u[j] = a[i];
            u_n += 1;
        }
    }

	// Count Duplicates
	for(i = 0; i < u_n; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(u[i] == a[j])
			{
				occ[i] += 1;
				continue;
			}
		}
	}
	
	for(i = 0; i < u_n; i++)
	{
		printf("%d appeared %d times\n",u[i],occ[i]);
		if(occ[i] > 1)
		{
			d_c += occ[i] - 1;
		}
	}

	printf("Total Duplicate numbers are: %d\n",d_c);
	return 0;	
}
