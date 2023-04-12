using namespace std;

class Quadratic
{
    private:
        float a;
        float b;
        float c;
    public:
        Quadratic()
        {
            a = 0; 
            b = 0; 
            c = 0;
        }
        Quadratic(float x, float y, float z);
        ~Quadratic();
        int getParameters();
        int findRoots();
};