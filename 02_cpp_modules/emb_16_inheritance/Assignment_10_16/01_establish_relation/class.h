#ifndef __CLASSES_H__
#define __CLASSES_H__

class Bclass
{
    private:
        int ba;
    protected:
        int bb;
    public:
        int funcBc();
        int displayB();
};

class Dclass: public Bclass
{
    private:
        int da;
    public:
        int funcDC();
        int displayD();
};


#endif