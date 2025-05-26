#pragma once

#include <iostream>
#include <string>

class staff
{
private:
    int code;
    std::string name;
    static int count;
public:
    staff();
    void getInformation(void);
    void display(void);
    int totalStaff(void);
};


