#pragma once

#include <iostream>
#include <string>

class bankAccount
{
private:
    std::string name;
    int accNumber;
    std::string acType;
    float balance;
public:
    void startAccount(void);
    void depositAmount(int amount);
    void withdrawAmount(int amount);
    void displayInformation(void);
};
