using namespace std;

class circle
{
    int rad;
    float area;
    public:
        circle();
        circle(int);
        void displayCircle(void);
        circle operator + (circle);
};