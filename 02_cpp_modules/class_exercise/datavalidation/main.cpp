#include<iostream>

using namespace std;

int main()
{
	int number;
	while(1)
	{
		cout<<"enter any number: "<< endl;
		cin >> number;
		if(cin.good())
		{
			cout<<"entered number is in good condition"<<endl;
			cout<<"entered number is: "<<number<<endl;
		}
				
		else
		{
			cin.ignore(10,'\n');
			cin.clear();
			cin.ignore(10,'\n');
			cout<<"Error: Please enter an integer"<<endl;
		}	
	}

	return 0;

}
