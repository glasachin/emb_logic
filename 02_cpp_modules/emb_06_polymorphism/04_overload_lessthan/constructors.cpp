#include"includes.h"
#include"classes.h"

Rectangle::Rectangle()
{
	len = 0;
	wid = 0;
	area = 0;
}

Rectangle::Rectangle(int dim)
{
	len = dim;
	wid = dim;
	area = 0;
}

Rectangle::Rectangle(int l, int w)
{
	len = l;
	wid = w;
	area = 0;
}

Rectangle::Rectangle(Rectangle & r)
{
	len = r.len;
	wid = r.wid;
	area = r.area;
}
