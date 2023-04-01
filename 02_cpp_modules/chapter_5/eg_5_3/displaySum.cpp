#include"includes.h"
#include"declarations.h"

void ITEMS::displaySum(void)
{
    float sum = 0;
    for(int i = 0; i < count; i++)
    {
        sum += itemPrice[i];
    }
    cout << "\nTotal value: "<<sum << endl;
}