#include "main.hpp"

int main()
{
    int choice;
    std::vector<staff> *emp;
    std::cout << "          Welcome to the Staff Manager APP          " << std::endl;
    while (1)
    {
        std::cout << "***********MENU***************" << std::endl;
        std::cout << "1. Enter New Staff" << std::endl;
        std::cout << "2. Display Total Staff" << std::endl;
        std::cout << "3. Display Staff List" << std::endl;
        std::cout << "******************************" << std::endl;
        std::cout << std::endl
                  << "Enter Your Choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            emp.push_back(staff )
            break;

        default:
            break;
        }
    }
    return 0;
}