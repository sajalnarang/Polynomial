#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial()
{
	//default constructor
	n=0;
	for(int i=0;i<1000;i++)
	{
		a[i]=0;
		roots[i]=0;
		maxima[i]=0;
		minima[i]=0;
		inflection[i]=0;
	}	
}

Polynomial::Polynomial(int degree,double coeff[])				//Input constructor
{
	n=degree;
	for(int i=0;i<n;i++)
	{
		a[i]=coeff[i];
	}
}

Polynomial::Polynomial(const Polynomial &source)				//Copy constructor
{
	n=source.n;
	for(int i=0;i<n-1;i++)
	{
		a[i]=source.a[i];
		roots[i]=source.roots[i];
		maxima[i]=source.maxima[i];
		minima[i]=source.minima[i];
		inflection[i]=source.inflection[i];
	}
	roots[n-1]=source.roots[n-1];
	a[n-1]=source.a[n-1];
	a[n]=source.a[n];
}

void Polynomial::read()											//coefficient!=0
{
	cout<<"Enter number of terms"<<endl;
	int terms;
	cin>>terms;
	double temp[2][terms];
	n=0;
	for(int i=0;i<terms;i++)
	{
		cin>>temp[0][i];
		cin>>temp[1][i];
		if(temp[0][i]>n)
			n=temp[0][i];
		if(temp[1][i]!=0)
			a[(int)temp[0][i]]=temp[1][i];
	}
}

double Polynomial::operator()(double x)
{
	double value;
	for(int i=0;i<=n;i++)
	{
		value+=a[i]*(pow(x,i));
	}	
	return value;
}

void Polynomial::getDegree()
{
	for(int i=999;i>=0;i--)
		if(a[i]!=0)
		{
			n=i;
			return;
		}
}

void Polynomial::print()
{
	char sign='+';
	getDegree();
	if(abs(a[n])!=1)
		cout<<a[n];
	else if(a[n]==-1)
		cout<<"-";
	if(n>1)
		cout<<"x^"<<n;
	else if(n==1)
		cout<<"x";
	for(int i=n-1;i>=0;i--)
	{
		sign='+';
		if(a[i]<0)
			sign='-';
		if(a[i]==0)
			continue;
		else if(abs(a[i])==1)
			cout<<sign;
		else
			cout<<sign<<abs(a[i]);
		if(i>1)
			cout<<"x^"<<i;
		else if(i==1)
			cout<<"x";
	}
	cout<<endl;
}

Polynomial Polynomial::derivative()
{
	Polynomial df_dx;
	df_dx.n = n-1;
	for(int i=1;i<=n;i++)
		df_dx.a[i-1] = (i)*a[i];
	return df_dx;
}

Polynomial Polynomial::integral()		
{
	Polynomial integral;
	integral.n = n+1;
	for(int i=0;i<=n;i++)
		integral.a[i+1] = a[i]/(i+1);
	integral.a[0]=0;
	return integral;
}
/*
void Polynomial::root()
{
	//if()	
}
*/
Polynomial Polynomial::operator+(const Polynomial &p)
{
	Polynomial sum;
	if(n>=p.n)
	{
		sum.n=n;
		for(int i=0;i<=p.n;i++)
			sum.a[i]=a[i]+p.a[i];
		for(int i=p.n+1;i<=n;i++)
			sum.a[i]=a[i];
	}
	else
	{
		sum.n=p.n;
		for(int i=0;i<=n;i++)
			sum.a[i]=a[i]+p.a[i];
		for(int i=n+1;i<=p.n;i++)
			sum.a[i]=p.a[i];
	}
	return sum;
}

Polynomial Polynomial::operator-(const Polynomial &p)
{
	Polynomial difference;
	if(n>=p.n)
	{
		difference.n=n;
		for(int i=0;i<=p.n;i++)
			difference.a[i]=a[i]-p.a[i];
		for(int i=p.n+1;i<=n;i++)
			difference.a[i]=a[i];
	}
	else
	{
		difference.n=p.n;
		for(int i=0;i<=n;i++)
			difference.a[i]=a[i]-p.a[i];
		for(int i=n+1;i<=p.n;i++)
			difference.a[i]=0-p.a[i];
	}
	return difference;
}

Polynomial Polynomial::operator*(const Polynomial &p)
{
	Polynomial product;
	product.n=n+p.n;
	for(int i=0;i<=n;i++)
	{
		int k=0;
		for(int j=0;j<=p.n;j++)
		{
			if(i+j==k)
				product.a[k]+=a[i]*p.a[j];
			k++;
		}	
		
	}
	product.a[product.n]=a[n]*p.a[p.n];
	return product;
}

Polynomial Polynomial::operator/(const Polynomial &q)
{
	Polynomial p(n,a);
	Polynomial quotient(p);
	quotient.n=p.n-q.n;
	if(n<q.n)
	{
		return quotient;
	}
	else
	{
		Polynomial s1;
		s1.n=quotient.n;
		s1.a[(s1.n)]=a[n]/q.a[q.n];
		s1.print();
		Polynomial s2=s1*q;
		s2.print();
		Polynomial s3=p-s2;
		s3.print();
		quotient = s1 + (s2/q);
		quotient.print();
	}
}
/*
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
}*/
