#ifndef __BOX_H__
#define __BOX_H__

#include <iostream>
#include <iomanip>

class box
{
private:
    double length{1.0};
    double width{1.0};
    double height{1.0};

public:
    box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv}
    {
    }

    box() = default; // No-arg constructor

    double volume() const
    {
        return length*width*height;
    }

    double getLength()
    {
        return length;
    }

    double getWidth()
    {
        return width;
    }

    double getHeight()
    {
        return height;
    }
};

inline std::ostream & operator << (std::ostream & stream, box & box1)
{
    stream << " Box(" << std::setw(2) << box1.getLength() << ',' 
            << std::setw(2) << box1.getWidth() << ','
            << std::setw(2) << box1.getHeight() << ')';
    return stream;
}

#endif __BOX_H__