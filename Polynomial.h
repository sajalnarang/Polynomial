#include<iostream>
#include<cmath>
using namespace std;

class Polynomial{
	private:
	
	int n,numberofroots=0;	//n = degree of polynomial
	double a[n+1];			//a = array of coefficients where a[i] is the coefficient of x^i
	double roots[n];
	double maxima[n-1],minima[n-1],inflection[n-1];	//arrays of coordinates of maxima, minima and points of inflection
		
	public:
	
	Polynomial();
	Polynomial(int n,double a[]);
	Polynomial(const Polynomial &source);
	double valueAt(double x);	//to be changed
	void read();
	void print();
	Polynomial derivative(const Polynomial &funtion);	//derivand
	Polynomial integral(const Polynomial &function);	//integrand
	void plot(double xleft,double xright);
	void root();
	Polynomial operator+(const Polynomial &p);	//this.+(p) == this+p
	Polynomial operator-(const Polynomial &p);	//this.-(p) == this-p
	Polynomial operator*(const Polynomial &p);	//this.*(p) == this*p
	Polynomial operator/(const Polynomial &p);	//this./(p) == this/p
	Polynomial operator%(const Polynomial &p);	//this.%(p) == this%p
	Polynomial operator^(const int &n);			//this.^(n) == this^n
	double getMaximumValue(double xleft,double xright);	//local maximum
	double getMaximumValue();							//global maximum
	double getMaxima(double xleft,double xright);		//x-coordinate at which local maxima occurs
	double getMaxima();									//x-coordinate at which global maxima occurs
	double getMinimumValue(double xleft,double xright);	//local minimum
	double getMinimumValue();							//global minimum
	double getMinima(double xleft,double xright);		//x-coordinate at which local minima occurs
	double getMinima();									//x-coordinate at which global minima occurs	
}
