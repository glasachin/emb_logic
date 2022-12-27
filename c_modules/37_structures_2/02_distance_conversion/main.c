#include "headers.h"
#include "declarations.h"



int main()
{
    dis_feet_inch d1,d2,d3;
    d1 = Input();
    d2 = Input();
    printf("Entered First distance is: \n");
    Display(d1);
    printf("Entered Second distance is: \n");
    Display(d2);
    d3 = AddDist(d1,d2);
    printf("Sum of two distances is: \n");
    Display(d3);
    printf("Sum of distances in m-cm is: \n");
    Convert(d3);
    return 0;
}