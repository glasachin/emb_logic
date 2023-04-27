#include"includes.h"
#include"classes.h"

int main()
{
	int a;
	Rectangle r1(10,30), r2(10);

	r1.computeArea();
	r2.computeArea();
	if(r1 < r2)
		cout<<"r1 is less than r2"<<endl;
	else if(r1>r2)
		cout <<"r1 is greater than r2"<<endl;
	else
		cout<<"temp"<<endl;

	return 0;
}

