#include <iostream>
#include <string>

std::string capitalizeWord(std::string s)
{
    s[0] = std::toupper(s[0]);

    // std::cout << "string length: " << s.length() << std::endl;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            s[i + 1] = std::toupper(s[i + 1]);
        }
    }

    return s;
}

int main()
{
    std::string s;
    std::cout << "Enter any string: ";
    getline(std::cin, s);
    std::cout << "Entered String is: " << s << std::endl;

    std::cout << "Modified String is: " << capitalizeWord(s) << std::endl;
    return 0;
}