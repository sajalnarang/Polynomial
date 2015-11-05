#include<simplecpp>

void Polynomial::plot()
{
	initCanvas("Polynomial",200,2*max(abs(maximum),abs(minimum)));
	Line yaxis(100,0,100,(2*max(abs(maximum),abs(minimum))));
	Line xaxis(0,max(abs(maximum),abs(minimum)),200,max(abs(maximum),abs(minimum)));
	for(int i=0;i<200;i+=0.01)
	{
		Line dl(i,this.p(i-100),i+1,this.p(i-100);
		dl.imprint();
	}
}
