#pragma once
#include <string>
#include "staff.hpp"

class teacher : public staff
{
private:
    std::string subject;
    int publications;

public:
    teacher();
};
