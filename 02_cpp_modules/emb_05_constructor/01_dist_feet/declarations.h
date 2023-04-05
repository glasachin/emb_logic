using namespace std;

class distance1
{
    private:
        int feet;
        float inches;
    public:
        distance1();
        distance1(float dis);
        distance1(int f, int i);
        ~distance1();
        void add_distance(distance1 d1, distance1 d2);
        void display(void);
};

