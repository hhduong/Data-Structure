#include <iostream>
using namespace std;
#include "lish.h"
#include "date.h"
#include "stack.h"
#include "quene.h"
int main()
{
	/*Stack<int> s;
	s.Push(10);
	s.Push(15);
	s.Push(30);
	cout<<s.Pop()<<endl;
	cout<<s.Pop()<<endl;
	cout<<s.Pop()<<endl;
	cout<<s.Pop()<<endl;*/
	Quene<int> q;
	q.EndQuene(10);
	q.EndQuene(15);
	q.EndQuene(30);
	cout<<q.DeQuene()<<endl;
	cout<<q.DeQuene()<<endl;

	return 0;
}