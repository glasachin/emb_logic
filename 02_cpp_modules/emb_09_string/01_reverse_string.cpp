#include <iostream>
#include <string>

std::string reverseString(std::string s)
{
    std::string s2;
    int i;
    i = s.length();
    s2 = s;
    for (int l = 0; l < s.length(); l++)
    {
        s2[l] = s[i - 1];
        // std::cout << "character: " << s[i - 1] << std::endl;
        i--;
    }
    return s2;
}

int main()
{
    std::string s1, s2;
    s2[0] = 's';
    std::cout << "first letter: " << s2 << std::endl; // wrong

    std::cout << "Enter any string: " << std::endl;
    std::cin >> s1;
    std::cout << "entered String: " << s1 << std::endl;

    std::cout << "reverse string is : " << reverseString(s1) << std::endl;

    return 0;
}


