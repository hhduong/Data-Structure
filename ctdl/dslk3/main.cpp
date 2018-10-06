#include <iostream>
using namespace std;
#include "node.h"
#include "list.h"

int main()
{
	List<int> t;
	t.addBack(5);
	t.addBack(5);
	t.addBack(5);
	t.addBack(5);
	t.PrintAll();
	return 0;
}