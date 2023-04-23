#include"includes.h"
#include"classes.h"

void operator = (dismeter d1, disfeet d2)
{
    float temp_inches, temp_cm;
    temp_inches = d2.feet*12+d2.inches;
    temp_cm = temp_inches*2.54;

    d1.meter = temp_cm % 100;
    d1.cm = temp_cm - d1.meter*100;
    
}

void operator = (disfeet d1, dismeter d2)
{
    float temp_inches, temp_cm;
    temp_cm = d2.meter*100+d2.cm;
    temp_inches = temp_cm*0.393701;

    d1.feet = temp_inches % 12;
    d1.inches = temp_inches - d1.feet*12;
    
}