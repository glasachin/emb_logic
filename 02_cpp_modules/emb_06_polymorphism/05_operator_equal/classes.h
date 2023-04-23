using namespace std;

class disfeet;

class dismeter
{
    int meter;
    int cm;
    public:
        dismeter();
        dismeter(int, int);
        void displayDismeter(void);
        void operator = (const dismeter, const disfeet);
        friend void operator = (disfeet, dismeter);
};

class disfeet
{
    int feet;
    int inches;
    public:
        disfeet();
        disfeet(int, int);
        void displayDisfeet(void);
        friend void operator = (dismeter, disfeet);
        friend void operator = (disfeet, dismeter );
};