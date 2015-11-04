#include<iostream>
#include<cmath>
using namespace std;

class Polynomial
{
	private:
	int n;												//n = degree of polynomial
	double a[1000];
	double roots[1000];
	double maxima[1000],minima[1000],inflection[1000];		//arrays of coordinates of maxima, minima and points of inflection
		
	public:
	
	Polynomial();
	Polynomial(int n,double a[]);
	Polynomial(const Polynomial &source);
	void read();
	void print();
	void getDegree();
	Polynomial derivative();
	Polynomial integral();
	void plot(double xleft,double xright);
	void root();
	double operator()(double x);
	Polynomial operator+(const Polynomial &p);	//this.+(p) == this+p
	Polynomial operator-(const Polynomial &p);	//this.-(p) == this-p
	Polynomial operator*(const Polynomial &p);	//this.*(p) == this*p
	Polynomial operator/(const Polynomial &q);	//this./(p) == this/p
	Polynomial operator%(const Polynomial &q);	//this.%(p) == this%p
	Polynomial operator^(const int &n);			//this.^(n) == this^n
	double getMaximumValue(double xleft,double xright);	//local maximum
	double getMaximumValue();							//global maximum
	double getMaxima(double xleft,double xright);		//x-coordinate at which local maxima occurs
	double getMaxima();									//x-coordinate at which global maxima occurs
	double getMinimumValue(double xleft,double xright);	//local minimum
	double getMinimumValue();							//global minimum
	double getMinima(double xleft,double xright);		//x-coordinate at which local minima occurs
	double getMinima();									//x-coordinate at which global minima occurs	
};
