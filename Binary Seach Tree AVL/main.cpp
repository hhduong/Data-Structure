#include <iostream>
using namespace std;
#include "AVLtree.h"

int main()
{
	
	TreeAVL<int> t;
	t.AddChild(87);
	t.AddChild(5);
    t.AddChild(52);
    t.AddChild(92);
    t.AddChild(12);
    t.AddChild(24);
    t.Preorder();
	return 0;
}
