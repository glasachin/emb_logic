#include<stdio.h>
#define N 10
int main()
{
	int a[N],u[N],u_n = 0,o[N],occ[N] = {0},loc[N];
	int i, j, d_c=0, a_l = 0;
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
            loc[j] = i;
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
	
    a_l = N;
	for(i = 0; i < u_n; i++)
	{
		printf("%d appeared %d times\n",u[i],occ[i]);
		if(occ[i] > 1)
		{
			d_c += occ[i] - 1;
            for( j = loc[i]; j < a_l-1; j++)
            {
                a[j] = a[j+1];
            }
            a_l--;
            for( j = i; j < u_n; j++)
                loc[i] -= occ[i];
		}
	}

	// printf("Total Duplicate numbers are: %d\n",d_c);
	printf("Original Array after deleting duplicate elements: \n");
    for(i = 0; i < a_l; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    
    return 0;	
}
