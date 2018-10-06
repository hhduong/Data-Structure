#include <iostream>
using namespace std;
#include "polynomial.h"
int main()
{

	Polynomial<float> p(4);
	p.Print();

	p.SetHeSo(2,5);

	p.Print();

	p.SetHeSo(3,0);

	p.Print();

	p.SetHeSo(1,-4);

	p.Print();

	cout<<p.Cal(2)<<endl;

	p = p*2; 

	p.Print();
		
	return 0;
}



