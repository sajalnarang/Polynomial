#include "Polynomial.h"
using namespace std;

void Polynomial::read()
{
	double coeff;
	char answer='y';
	cin >> answer;
	int count =0;
	while (answer=='y'||answer=='Y')
	{
		cout << "Enter coefficient of x^"<<count<<" : " ;
		cin >> coeff;
		a.push_back(coeff);
		cout << "Continue taking input? (y/n) " ;
		cin >> answer;
		count ++ ;
	}
}

Polynomial::Polynomial()	//Polynomial constructor
{
	read();
	n = a.size();
	roots.assign(n,0);
	maxima.assign(n-1,0);
	minima.assign(n-1,0);
	inflection.assign(n-1,0);
}

Polynomial::Polynomial(int degree,vector<double> coefficient)		//Input constructor
{
	n=degree;
	for(int i=0;i<=n;i++)
		coefficient.push_back(a[i]);
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
		source.a.push_back(a[i]);
	for(int i=0;i<=n-1;i++)
		source.roots.push_back(roots[i]);
	for(int i=0;i<=n-2;i++)
	{
		source.maxima.push_back(maxima[i]);
		source.minima.push_back(minima[i]);
		source.inflection.push_back(inflection[i]);
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

void Polynomial::print()
{
	for(int i=n;i>=0;i--)
		cout<<a[i]<<"x^"<<i<<endl;	//TBD implementation of superscript
}

Polynomial Polynomial::derivative()
{
	Polynomial df_dx;
	df_dx.n = n-1;
	df_dx.a.assign(n-1,0);
	for(int i=1;i<=n-1;i++)
		df_dx.a[i-1] = i*a[i];
	return df_dx;
}

Polynomial Polynomial::integral()		//TBD implementation of constant of integration
{
	Polynomial integral;
	integral.n = n+1;
	integral.a.assign(n+1,0);
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
	if(n>=p.n)
	{
		sum.n=n;
		for(int i=0;i<p.n;i++)
			sum.a[i]=a[i]+p.a[i];
		for(i=p.n;i<n;i++)
			sum.a[i]=a[i];
	}
	else
		sum = p + this ;
	
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
	product.a.assign(n+p.n,0);
	for(int i=0;i<=n;i++)
	{
		int k=0;
		for(int j=0;j<=n;j++)
		{
			if(i+j==k)
				product.a[k]+=a[i]*a[j];
		
		}	
		k++;
	}
	return product;
}

Polynomial Polynomial::operator/(Polynomial &p)
{
	Polynomial quotient;
	int m;
	m = p.n;
	quotient.n=n-m;
	Polynomial q;
	q.Polynomial(n,a);
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
	else
		cout << "No polynomial obtained"<<endl;
	return quotient;
}

Polynomial Polynomial::operator%(const Polynomial &p)
{
	Polynomial remainder;
	Polynomial q;
	q.Polynomial(this);
	if(n>p.n)
		remainder = q-((q/p)*p);
	else
		remainder =  this ;
}

Polynomial Polynomial::operator^(const int &power)
{
	Polynomial nth_power;
	for(int i=1;i<=power;i++)
		nth_power = nth_power*nth_power;
	return nth_power;
}


