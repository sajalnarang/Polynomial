#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Polynomial{
	private:
	
	static int n;	//n = degree of polynomial
	vector<double> a ;
	vector<double> roots ;
	vector<double> maxima,minima,inflection;	//arrays of coordinates of maxima, minima and points of inflection
		
	public:
	
	Polynomial();
	Polynomial(int n,vector<double> coefficient);
	Polynomial(const Polynomial &source);
	double valueAt(double x);	//to be changed
	void read();
	void print();
	Polynomial derivative();	//derivand
	Polynomial integral();	//integrand
	void plot(double xleft,double xright);
	void root();
	Polynomial operator+(const Polynomial &p);	//this.+(p) == this+p
	Polynomial operator-(const Polynomial &p);	//this.-(p) == this-p
	Polynomial operator*(Polynomial &p);			//this.*(p) == this*p
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
};
