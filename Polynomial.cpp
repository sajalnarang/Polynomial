#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial()	//Zero constructor
{
	n=0;
	a[0]=0;
}

Polynomial::Polynomial(int degree,double coefficient[])		//Input constructor
{
	n=degree;
	for(int i=0;i<=n;i++)
		a[i]=coefficient[i];
	for(int i=0;i<=n-1;i++)
		roots[i]="\0";
	for(int i=0;i<=n-2;i++)
	{
		maxima[i]="\0";
		minima[i]="\0";
		inflection[i]="\0";
	}
}

Polynomial::Polynomial(const Polynomial &source)		//Copy constructor
{
	n = source.n;
	for(int i=0;i<=n;i++)
		a[i]=source.a[i];
	for(int i=0;i<=n-1;i++)
		roots[i]=source.roots[i];
	for(int i=0;i<=n-2;i++)
	{
		maxima[i]=source.maxima[i];
		minima[i]=source.minima[i];
		inflection[i]=source.inflection[i];
	}
}

double Polynomial::ValueAt(double x)
{
	double value;
	for(int i=0;i<=n;i++)
	{
		value+=a[i]*(pow(x,i));
	}	
	return value;
}

void Polynomial::read()
{
	//TBD
}

void Polynomial::print()
{
	for(i=n;i>=0;i--)
		cout<<a[i]<<"x^"<<i<<endl;	//TBD implementation of superscript
}

Polynomial Polynomial::derivative()
{
	Polynomial df_dx;
	df_dx.n = n-1;
	for(int i=1;i<=n-1;i++)
		df_dx.a[i-1] = i*a[i];
	return df_dx;
}

Polynomial Polynomial::integral()		//TBD implementation of constant of integration
{
	Polynomial integral;
	integral.n = n+1;
	for(int i=0;i<=n;i++)
		integral.a[i+1] = a[i]/i+1;
	return integral;
}

void Polynomial::root()
{
	//if()	
}

Polynomial Polynomial::operator+(const Polynomial &p)
{
	Polynomial sum;
	if(n>p.n)
	{
		sum.n=n;
		for(int i=0;i<p.n;i++)
			sum.a[i]=a[i]+p.a[i];
		for(i=p.n;i<n;i++)
			sum.a[i]=a[i];
	}
	else
	{
		sum.n=p.n;
		for(int i=0;i<n;i++)
			sum.a[i]=a[i]+p.a[i];
		for(i=n;i<p.n;i++)
			sum.a[i]=p.a[i];
	}
	return sum;
}

Polynomial Polynomial::operator-(const Polynomial &p)
{
	Polynomial difference;
	if(n>p.n)
	{
		difference.n=n;
		for(int i=0;i<p.n;i++)
			difference.a[i]=a[i]-p.a[i];
		for(i=p.n;i<n;i++)
			difference.a[i]=a[i];
	}
	else
	{
		difference.n=p.n;
		for(int i=0;i<n;i++)
			difference.a[i]=a[i]-p.a[i];
		for(i=n;i<p.n;i++)
			difference.a[i]=p.a[i];
	}
	return difference;
}

Polynomial Polynomial::operator*(const Polynomial &p)
{
	Polynomial product;
	for(int i=0;i<=n;i++)
	{
		int k=0;
		for(int j=0;j<=n;j++)
		{
			if(i+j==k)
				product.[k]+=a[i]*a[j];
		
		}	
		k++;
	}
	return product;
}

Polynomial Polynomial::operator/(const Polynomial &p)
{
	Polynomial quotient;
	p.n=m;
	quotient.n=n-m;
	Polynomial q;
	q.Polynomial(n,a[]);
	if(n>=m)
	{
		while((q.n)>=m)
		{
			quotient.a[n-m]=(q.[n]/p.a[m]);
			p = p*quotient;
			q = q-p;
			(q.n)--;
		}
	}
	return quotient;
	else
		quotient.Polynomial();
}

Polynomial Polynomial::operator%(const Polynomial &p)
{
	Polynomial remainder;
	Polynomial q;
	q.Polynomial(n,a[]);
	remainder = q-((q/p)*p);
}

Polynomial Polynomial::operator^(const int &power)
{
	Polynomial nth_power
	for(int i=1;i<=power;i++)
		nth_power = nth_power*nth_power;
	return nth_power;
}

double Polynomial::getMaximumValue(double xleft,double xright)
{

}

