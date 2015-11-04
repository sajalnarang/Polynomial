#include "Polynomial.h"

int main()
{
	Polynomial p;
	p.read();
	cout<<p(2)<<endl;
	Polynomial q = p.derivative();
	Polynomial r = p.integral();
	/*p.print();
	q.print();
	r.print();
	cout<<q(1)<<endl;
	cout<<r(1)<<endl;*/
	Polynomial s = p / q;
	s.print();
	
}
