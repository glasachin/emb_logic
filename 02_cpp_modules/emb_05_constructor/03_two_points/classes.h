using namespace std;

class point
{
    int x;
    int y;
    public:
        point();
        point(int x1, int y1);
        point(point & p);
        ~point();
        int getPoint(); //do not use void
        float getDistance(point p);
};