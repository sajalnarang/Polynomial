#include "Polynomial.h"

double Polynomial::singleRoot()
{
	double x=0 ;
	double epsilon = 0.000000001
	Polynomial q(n,a);
	Polynomial df_dx(q.derivative());
	while(abs(q(x))>epsilon)
	{
		if(df_dx(x)!=0)
		{
			x = x - (q(x)/df_dx(x));
			for(int i=0;i<n;i++)
			{
				if(roots[i]==x)
					x+=0.1;
			}
		}
		else
			x+=0.1;
	}
	return x;
}

void Polynomial::root()
{
	Polynomial p(n,a);
	for(int i=0;i<n;i++)
	{
		double x = p.singleRoot();
		roots[i]=x;
		double arr[2] = {-x,1};
		Polynomial q(1,arr);
		p=p/q;
	}
}

void Polynomial::printRoots()
{
	getDegree();
	for(int i=0;i<n-1;i++)
	{
		cout << roots[i] << " , ";
	}
	cout << roots[n-1] << endl;
}
