using namespace std;

class Rectangle
{
	private:
		int len;
		int wid;
		int perimeter;
		int area;

	public:
		Rectangle();
		Rectangle(int dim);
		Rectangle(int l, int w);
		Rectangle(Rectangle & r);
		int getDimesnion();
		int computeArea();
		int computePerimeter();
		int operator < (Rectangle);
		int operator > (Rectangle);
		int operator == (Rectangle);
		int operator != (Rectangle);
		int operator <= (Rectangle);
		int operator >= (Rectangle);
};

