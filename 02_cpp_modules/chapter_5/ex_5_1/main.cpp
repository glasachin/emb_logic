#include "bank.h"

int main()
{
    int choice;
    int cont = 1;
    bankAccount ac;
    while(cont)
    {
        std::cout << "1. Create Account" << std::endl
            << "2. Display Account" << std::endl
            << "3. Deposit Amount " << std::endl
            << "4. Withdraw Amount " << std::endl
            << "0. Exit" << std::endl
            << "Enter your choice: " ;
        
        std::cin >> choice;
        switch(choice)
        {
            case 1:
                ac.startAccount();
                break;
            case 2:
                ac.displayInformation();
                break;
            case 3:
                ac.depositAmount();
                break;
            case 4:
                ac.withdrawAmount();
                break;
            case 0:
                std::cout <<"------------BYE--------------" << std::endl;
                exit(0);
                break;
            default:
                std::cout << "Wrong Choice, Enter again..." << std::endl;
                break;
        }
    }
    return 0;
}
