#include <iostream>
#include "hashtable.h"
using namespace std;

int main()
{
	HashTable H;
	H.Insert(1,3);
	H.Insert(3,7);
	H.Insert(4,9);
	//H.search(1);
	H.Display();
	cout<<H.Delete(1)<<endl;
	H.Display();
	return 0;
}