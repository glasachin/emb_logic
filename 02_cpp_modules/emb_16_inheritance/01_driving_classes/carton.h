#ifndef __CARTON_H__
#define __CARTON_H__

#include <string>
#include <string_view>
#include <iostream>
#include "box.h"
using namespace std;
class carton : public box
{
    private:
        std:: string material;
    public:
        explicit carton(std::string_view mat = "cardboard") : material{mat} {}
};
#endif