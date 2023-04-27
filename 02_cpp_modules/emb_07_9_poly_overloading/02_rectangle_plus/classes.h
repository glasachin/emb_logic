using namespace std;

class rectangle
{
    int length;
    int width;
    public:
        rectangle();
        rectangle(int, int);
        void displayRectangle(void);
        rectangle operator + (rectangle);
};