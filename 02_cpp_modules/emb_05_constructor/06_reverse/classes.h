using namespace std;

class reverse
{
    char a[10];
    public:
        reverse()
        {
            a[0] = '\n';
        }
        reverse(char *data);
        ~reverse();
        int doReverse();
};