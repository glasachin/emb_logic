#include "bank.h"

int main()
{
    int choice;
    int cont = 1;

    while(cont)
    {
        std::cout << "1. Create Account" << std::endl
            << "2. Display Account" << std::endl
            << "3. Deposit Amount " << std::endl
            << "4. Withdraw Amount " << std::endl
            << "0. Exit" << std::endl;
            << "Enter your choice: " ;
        
        std::cin >> choice;
    }
    return 0;
}
