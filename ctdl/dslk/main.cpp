#include <iostream>
using namespace std;
#include "list.h"
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
	/*Quene<int> q;
	q.EndQuene(10);
	q.EndQuene(15);
	q.EndQuene(30);
	cout<<q.DeQuene()<<endl;
	cout<<q.DeQuene()<<endl;*/

	List<int> l;
	l.Add(30);
	l.Add(10);
	l.Add(15);
	l.Add(20);
	l.Add(25);
	l.Add(20);
	//l.DeleteByValue(20);
	l.Sort_up_ascending();
	l.PrintAll();

	return 0;
}