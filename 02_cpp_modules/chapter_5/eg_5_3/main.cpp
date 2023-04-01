#include"includes.h"
#include"declarations.h"

int main()
{
    ITEMS order;
    order.CNT();
    int x;
    do
    {
        cout << "\n You can do the following;" << " Enter appropriate number \n" << endl;
        cout << "1: Add an item" << endl;
        cout << "2: Display total value" << endl;
        cout << "3: Delete an item" << endl;
        cout << "4: Display all items" << endl;
        cout << "5: Quit" << endl;
        cout << "What is your Option?" << endl;

        cin >> x;
        switch(x)
        {
            case 1:
                order.getitem();
                break;
            case 2:
                order.displaySum();
                break;
            case 3:
                order.remove();
                break;
            case 4:
                order.displayItem();
                break;
            case 5:
                break;
            default:
                cout << "Wrong Choice! Please enter your choice again.\n" << endl;
        }
    } while (x!=5);
    return 0;
}