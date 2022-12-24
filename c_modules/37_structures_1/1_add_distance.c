#include<stdio.h>
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

int main()
{
    distance *d1, *d2, *d3;
    printf("Enter the 1st distance: \n");
    get_distance(d1);
    printf("Enter 2nd distance: \n");
    get_distance(d2);
    d3 = add_distance(d1,d2);
    printf("Feet: %d, Inches: %d\n",d3->feet,d3->inches);
    return 0;
}
