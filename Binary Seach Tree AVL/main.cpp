#include <iostream>
using namespace std;
#include "AVLtree.h"

int main()
{
	
	TreeAVL<int> t;
	t.AddChild(30);
	t.AddChild(5);
    t.AddChild(35);
    t.AddChild(32);
    t.AddChild(40);
    t.AddChild(45);
    t.Preorder();
	return 0;
}
