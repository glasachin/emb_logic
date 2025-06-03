#include "main.hpp"

int main()
{
    int choice, staffCounter = 0;
    std::vector<staff> emp;
    std::cout << "          Welcome to the Staff Manager APP          " << std::endl;
    while (1)
    {
        std::cout << "***********MENU***************" << std::endl;
        std::cout << "1. Enter New Staff" << std::endl;
        std::cout << "2. Display Total Staff" << std::endl;
        std::cout << "3. Display Staff List" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "******************************" << std::endl;
        std::cout << std::endl
                  << "Enter Your Choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            // emp.emplace_back();
            emp.push_back(staff());
            emp[staffCounter].getInformation();
            staffCounter++;
            std::cout << std::endl;
            break;
        case 2:
            if (staffCounter == 0)
            {
                std::cout << "No Staff" << std::endl;
                continue;
            }
            std::cout << "Total Staff: " << staffCounter;
            std::cout << std::endl;
            break;
        case 3:
            if (staffCounter > 0)
            {
                for (int i = 0; i < staffCounter; i++)
                {
                    emp[i].display();
                }
            }
            else
            {
                std::cout << "No Staff to display." << std::endl;
            }
            std::cout << std::endl;
            break;
        case 0:
            goto exit;
            break;
        default:
            break;
        }
    }

exit:
    return 0;
}