#include "bank.h"

bankAccount::bankAccount()
{
    balance = 0.0;
    accNumber = 0;
}

void bankAccount::startAccount(void)
{
    std::cout << "Welcome to New Account Creation ==>" << std::endl;
    std::cout << "Enter Your Name: ";
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << "Enter the Depositing Amount: ";
    std::cin >> balance;
    std::cout << "Enter the Account Type: ";
    std::cin.ignore();
    getline(std::cin, acType);
    // generate random account number
    accNumber = std::rand();
    std::cout << "Your Assigned Account Number is: " << accNumber << std::endl;
}

void bankAccount::depositAmount(void)
{
    int depositAmount;
    std::cout << "Enter the amount to be deposited: ";
    std::cin >> depositAmount;
    balance += depositAmount;
    std::cout << "Amount deposited successfully...." << std::endl;
    std::cout << "Final Balance: " << balance << std::endl;
}

void bankAccount::withdrawAmount(void)
{
    int withdrawAmount;
    std::cout << "Enter the amount to be withdraws: ";
    std::cin >> withdrawAmount;
    if (withdrawAmount > balance)
    {
        std::cout << "Not enough balance!!!" << std::endl;
    }
    else
    {
        balance -= withdrawAmount;
        std::cout << "Withdraw Success!!!" << std::endl;
        std::cout << "Remaining Amount is: " << balance << std::endl;
    }
}

void bankAccount::displayInformation(void)
{
    std::cout << "Account Number: " << accNumber << std::endl
            << "Account Type: " << acType << std::endl
            << "Account Holder: " << name << std::endl
            << "Balance: " << balance << std::endl; 
}
