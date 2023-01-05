#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    /* data */
    int feet;
    int inches;
}distance;

void get_distance(distance *d)
{
    printf("Enter feet: ");
    scanf("%d",&d->feet);
    printf("Enter inches: ");
    scanf("%d",&d->inches);
}

distance* add_distance(distance *d1, distance *d2)
{
    distance *d;
    d->inches = d1->inches+d2->inches;
    d->feet = d1->feet+d2->feet;
    if(d->inches > 12)
    {
        d->inches -= 12;
        d->feet+=1;
    }
    return d;
}

typedef struct 
{
    int a;
    int *ft;
    int *inch;
}dis_feet_inch;

typedef struct 
{
    /* data */
    dis_feet_inch *ds;
}dis;


int main()
{
    distance *d1, *d2, *d3;
    dis_feet_inch *d;
    dis *di;
    d->a = 10;
    di=(dis*)malloc(sizeof(dis));
    di->ds = (dis_feet_inch*)malloc(sizeof(dis_feet_inch));
    di->ds->a = 100;
    printf("%d\n", d->a);
    printf("di: %d\n",di->ds->a);
    printf("Enter the 1st distance: \n");
    get_distance(d1);
    printf("Enter 2nd distance: \n");
    get_distance(d2);
    d3 = add_distance(d1,d2);
    printf("Feet: %d, Inches: %d\n",d3->feet,d3->inches);
    return 0;
}
