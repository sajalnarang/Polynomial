#include "Polynomial.h"

int main()
{
	Polynomial p,q;
	p.read();
	q.read();
	Polynomial r=p/q;
	r.print();
}
