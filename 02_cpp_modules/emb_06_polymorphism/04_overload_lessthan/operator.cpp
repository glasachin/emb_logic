#include"includes.h"
#include"classes.h"

Rectangle Rectangle::operator < (Rectangle r1) const
{
 if(r1.computeArea > r2.computeArea)
 {
	 cout << "r1 rectangle is bigger" << endl;
	 return r1;
 }
 else
 {
	 cout << "r2 rectangle is bigger" << endl;
	 return r2;
 }
}
