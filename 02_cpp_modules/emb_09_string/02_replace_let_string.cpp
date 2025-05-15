#include <iostream>
#include <string>

std::string replaceLetter(std::string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (((s[i] >= 65) && (s[i] <= 90)) || ((s[i] >= 97) && (s[i] <= 122)))
        {
            if ((s[i] + 1) == 91)
                s[i] = 65;
            else if ((s[i] + 1) == 123)
                s[i] = 97;
            else
                s[i] = s[i] + 1;
        }
    }

    return s;
}

int main()
{
    std::string s;

    std::cout << "Enter any string: " << std::endl;
    std::cin >> s;
    std::cout << "Entered String is: " << s << std::endl;

    std::cout << "Modified String is: " << replaceLetter(s) << std::endl;

    return 0;
}