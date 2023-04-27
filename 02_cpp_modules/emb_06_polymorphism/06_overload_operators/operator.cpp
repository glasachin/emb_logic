#include"includes.h"
#include"classes.h"

// All these comparisons are based on area
int Rectangle::operator < (Rectangle r)
{
	if(area < r.area)
		return 1;
	else
		return 0;
}

int Rectangle::operator > (Rectangle r)
{
	if(area > r.area)
		return 1;
	else
		return 0;
}

int Rectangle::operator != (Rectangle r)
{
	if(area != r.area)
		return 1;
	else
		return 0;
}

int Rectangle::operator <= (Rectangle r)
{
	if(area <= r.area)
		return 1;
	else
		return 0;
}

int Rectangle::operator >= (Rectangle r)
{
	if(area >= r.area)
		return 1;
	else
		return 0;
}
