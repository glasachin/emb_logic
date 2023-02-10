#include "headers.h"
#include "declarations.h"

dis_feet_inch Input()
{
    dis_feet_inch dis;
    printf("Enter feet of distance: \n");
    scanf("%d",&dis.feet);
    printf("Enter inches of distance: \n");
    scanf("%d",&dis.inches);
    return dis;
}

void Display(dis_feet_inch dis)
{
    printf("Feet: %d, Inches: %d\n",dis.feet,dis.inches);
}

dis_feet_inch AddDist(dis_feet_inch d1, dis_feet_inch d2)
{
    dis_feet_inch d3;
    d3.feet = d1.feet+d2.feet;
    d3.inches = d1.inches+d2.inches;
    if(d3.inches > 12)
    {
        d3.feet += 1;
        d3.inches -= 12;
    }
    return d3;
}

void Convert(dis_feet_inch ds)
{
    dis_m_cm dm;
    float inch;
    float cm;
    inch = ds.feet*12+ds.inches;
    cm = inch*2.54;
    dm.m = (int)cm/100;
    dm.cm = (int)(cm - (float)dm.m*100);

    printf("m: %d, cm: %d\n",dm.m,dm.cm);
}