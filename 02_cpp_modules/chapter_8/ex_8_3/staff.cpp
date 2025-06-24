#include "staff.hpp"

int staff::count;

staff::staff(void)
{
    count++;
    std::cout << "Staff counter incremented" << std::endl;
}

void staff::getInformation(void)
{
    std::cout << "Enter Employee Code: ";
    std::cin >> code;
    std::cin.ignore();
    std::cout << "Enter Employee Name: ";
    getline(std::cin, name);
}

void staff::display(void)
{
    std::cout << "Staff Code: " << code
              << "\tStaff Name: " << name << std::endl;
}

int staff::totalStaff(void)
{
    std::cout << "Total Staff: " << count << std::endl;
    return count;
}
