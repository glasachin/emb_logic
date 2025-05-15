// https://www.w3resource.com/cpp-exercises/vector/cpp-vector-exercise-1.php#google_vignette
#include <iostream>
#include <vector>
#include <algorithm>

int check_Vector(std::vector<int> c)
{
    std::sort(c.begin(), c.end());
    std::cout << "sorted vector: " << std::endl;
    for (int i = 0; i < c.size(); i++)
    {
        std::cout << c[i];
    }
    std::cout << std::endl;

    // checking the continuity
    for (int i = 1; i < c.size(); i++)
    {
        if (c[i] != c[i - 1] + 1)
        {
            return -1;
        }
    }
    return 0;
}

int main()
{
    std::vector<int> a(5); // assigning 5 elements in vector a

    std::vector<int> b = {1, 3, 7, 0, 2, 4};

    int res = check_Vector(b);

    if (res == -1)
    {
        std::cout << "False" << std::endl;
    }
    else
    {
    std::cout << "True" << std::endl;
    }
    return 0;
}