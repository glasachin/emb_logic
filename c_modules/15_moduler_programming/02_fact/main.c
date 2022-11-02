#include "functions.h"
int main()
{
	int *p;
	p = get_input();
	p = compute_fact(p);
	print_fact(p);
	return 0;
}
