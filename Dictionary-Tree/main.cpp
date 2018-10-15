#include <iostream>
#include "dictree.h"
using namespace std;

int main()
{
	DicTree t;
	t.Add("HELLO");
    t.Add("HI");
    t.Add("BYE");
    t.Add("BOY");
    
    cout<<t.Search("BOY")<<endl;
    cout<<t.Search("NOW")<<endl;
	return 0;
}