#ifndef quene_h
#define quene_h
#include "list.h"
template <class T>
class Quene
{
private:
	Node<T> *top;
public:
	Quene()
	{
		top = 0;
	};
	void EndQuene(T newValue)
	{
		Node<T> *n = new Node<T>;
		n->data = newValue;
		n->next = 0;
		if(top == 0)
		{
			top = n;
		}
		else
		{
			Node<T> *p = top;
			while(n->next!=0)
			{
				p = p->next;
			}
			p->next = n;
		} 
	};

	T DeQuene()
	{
		T t = top->data;
		Node<T> *q = top;
		top = top->next;
		delete q;
		return t;
	};

	bool IsEmpty() const
	{
		return top==0;
	};
}