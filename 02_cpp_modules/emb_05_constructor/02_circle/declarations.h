using namespace std;

class Circle
{
    private:
        float r;
        float area;
        float perimeter;
    public:
        Circle();
        Circle(float rad);
        ~Circle();
        void getRadius(void);
        void calArea(void);
        void calParimeter(void);
};