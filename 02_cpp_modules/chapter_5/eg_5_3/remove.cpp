#include"includes.h"
#include"declarations.h"

void ITEMS::remove(void)
{
    int a;
    cout << "Enter item code to remove: ";
    cin >> a;

    for(int i = 0; i < count; i++)
    {
        if(itemCode[i] == a)
        {
            itemPrice[i] = 0;
            break;
        }
    }
}