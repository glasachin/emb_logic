#include<stdio.h>

typedef struct 
{
    /* data */
    int km;
    int m;
}km_m;

typedef struct 
{
    /* data */
    int m;
    int cm;
}m_cm;

void get_distance(km_m *d)
{
    printf("Enter KM: ");
    scanf("%d",&d->km);
    printf("Enter m: ");
    scanf("%d",&d->m);
}

m_cm* convert_distance(km_m *d)
{
    m_cm *d1;
    // write formula here
}

int main()
{
    km_m *d_km;
    m_cm *d_m;
    printf("Enter the distance in KM-M\n");
    get_distance(d_km);
}
