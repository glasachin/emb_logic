using namespace std;

class disfeet;

class dismeter
{
    float meter;
    float cm;
    public:
        dismeter();
        dismeter(int, int);
        void displayDismeter(void);
        void operator = (disfeet);
        
};

class disfeet
{
    float feet;
    float inches;
    public:
        disfeet();
        disfeet(int, int);
        void displayDisfeet(void);
        void operator = (dismeter);
};