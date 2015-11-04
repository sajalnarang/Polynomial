#include<simplecpp>

void Polynomial::plot()
{
	initCanvas("Polynomial",200,maximum-minimum+100);
	Line yaxis(100,0,100,(maximum-minimum+100));
	Line xaxis(0,(maximum-minimum+100)/2,200,(maximum-minimum+100)/2);
}
