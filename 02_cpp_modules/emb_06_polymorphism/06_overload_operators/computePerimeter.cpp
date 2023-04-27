#include"includes.h"
#include"classes.h"

int Rectangle::computePerimeter()
{
	perimeter = 2*(len + wid);
	return perimeter;
}
