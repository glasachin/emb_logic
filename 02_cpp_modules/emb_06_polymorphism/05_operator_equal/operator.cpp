#include"includes.h"
#include"classes.h"

void dismeter::operator = (disfeet d2)
{
    float temp_inches, temp_cm;
    temp_inches = d2.feet*12+d2.inches;
    temp_cm = temp_inches*2.54;

    meter = (int)temp_cm % 100;
    cm = temp_cm - meter*100;    
}

void disfeet::operator = (dismeter d2)
{
    float temp_inches, temp_cm;
    temp_cm = d2.meter*100+d2.cm;
    temp_inches = temp_cm*0.393701;

    feet = (int)temp_inches % 12;
    inches = temp_inches - feet*12;
}