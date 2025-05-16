#include "bank.h"

void bankAccount::startAccount(void)
{
    std::cout << "Welcome to New Account Creation ==>" << std::endl;
    std::cout << "Enter Your Name: " ;
    getline(std::cin, name);
    std::cout << "Enter the Depositing Amount: ";
    std::cin >> balance;
    // generate random account number
    std::cout << "Your Assigned Account Number is: " << accNumber << std::endl;
}

