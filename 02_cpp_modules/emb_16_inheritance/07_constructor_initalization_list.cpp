#include<iostream>
using namespace std;

class alpha{
    private:
        int x;
    public:
        alpha(int i)
        {
            x = i;
            cout << "alpha constructed\n";
        }

        void show_alpha(void)
        {
            cout << "x = " << x << "\n";
        }
};

class beta
{
    private:
        float p, q;
    public:
        beta(float a, float b): p(a), q(b+p)
        {
            cout << "beta constructed\n";
        }
        void show_beta(void)
        {
            cout << "p = " << p << "\n";
            cout << "q = " << q << "\n";
        }
};

class gamma: public beta, public alpha
{
    private:
        int u, v;
    public:
        gamma(int a, int b, float c):
        alpha(a*2), beta(c,c), u(a)
        {
            v = b;
            cout << "gamma constructed\n";
        }

        void show_gamma(void)
        {
            cout << "u = " << u << "\n";
            cout << "v = " << v << "\n";
        }
};

int main()
{
    gamma g(2, 4, 3.5);

    cout << "Display member values " << endl;
    g.show_alpha();
    g.show_beta();
    g.show_gamma();

    return 0;
}