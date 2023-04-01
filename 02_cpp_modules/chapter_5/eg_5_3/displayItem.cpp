#include"includes.h"
#include"declarations.h"

void ITEMS::displayItem(void)
{
    cout << "\nCode Price\n";
    for(int i = 0; i < count; i++)
    {
        cout <<"\n" <<itemCode[i];
        cout << " " << itemPrice[i];
    }
    cout << "\n";
}