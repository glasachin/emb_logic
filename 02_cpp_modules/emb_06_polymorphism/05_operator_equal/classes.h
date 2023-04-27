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
        void operator = (disfeet);
        
};

class disfeet
{
    int feet;
    int inches;
    public:
        disfeet();
        disfeet(int, int);
        void displayDisfeet(void);
        void operator = (dismeter);
};