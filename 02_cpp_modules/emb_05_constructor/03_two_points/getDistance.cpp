#include"includes.h"
#include"classes.h"

float point::getDistance(point p)
{
    float dis;
    dis = sqrt(pow(x - p.x,2)+pow(y - p.y, 2));
    return dis;
}