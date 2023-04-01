#include"includes.h"
#include"declarations.h"

void ITEMS::getitem(void)
{
    cout << "Enter Item Code : ";
    cin >> itemCode[count];
    cout << "Enter Item Price: ";
    cin >>  itemPrice[count];
    count++;
}