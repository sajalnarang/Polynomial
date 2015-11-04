#inlude<simplecpp>

double Polynomial::single_root()
{
	double x=0 ;
	long double epsilon = 0.00000000000000000001;
	Polynomial q(n,a);
	Polynomial df_dx = q.derivative();
	while(abs(q(x))>epsilon)
	{
		if(df_dx!=0)
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
	return x
}

void Polynomial::roots()
{
	Polynomial p(n,a);
	for(i=0;i<n;i++)
	{
		double x = p.single_root();
		roots[i]=x;
		Polynomial q(1,{-x,1});
		p=p/q;
	}
}

void Polynomial::printRoots()
{
	for(int i=0;i<n;i++)
	{
		cout << roots[i] << " , ";
	}
	cout << endl;
}