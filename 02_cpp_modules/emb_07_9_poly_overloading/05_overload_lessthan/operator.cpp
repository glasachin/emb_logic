#include"includes.h"
#include"classes.h"

Rectangle Rectangle::operator < (Rectangle r1) const
{
	if((len*wid) > r1.computeArea())
	{
		cout << "rectangle having len : "<< len <<" and width: " << wid <<" is bigger" << endl;
		
	}
	else
	{
		cout << "rectangle having len : "<< r1.len <<" and width: " << r1.wid <<" is bigger" << endl;
		
	}
	return r1;
}
