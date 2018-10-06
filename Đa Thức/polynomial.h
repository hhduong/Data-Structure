#ifndef polynomial_h
#define polynomial_h
#include "node.h"
#include <math.h>
template <class T>

class Polynomial
{
private:
	Node<T> *head;
public:
	Polynomial()
	{
		head = 0;
	};
	Polynomial(int b)
	{
		head = 0;
		Node<T> * p = head;
		for(int i = 0;i<=b;i++)
		{
			Node<T> *n = new Node<T>;
			n->bac = i;
			n->heso = 1;

			n->next = head;
			head = n;
		}
	};
	bool IsEmpty()
	{
		return head == 0;
	}
	
	void Print() const
	{
		Node<T> *p = head;
		while(p->next != 0)
		{

			if(p->heso == 1)
			{
				if(p-> bac != 1)
					cout<<"x^"<<p->bac;
				else
					cout<<"x";
			}
			else
			{
				if(	p->heso == -1)
				{
					if(p->bac == 1)
						cout<<"-x";
					else
						cout<<"-x^"<<p->bac;
				}
				else
				{
					if(p->heso >1)
					{
						cout<<p->heso<<"x^"<<p->bac;
					}
					else
					{
						if(	p->heso <0)
						{
							if(p->bac == 1)
								cout<<p->heso<<"x";
							else
								cout<<p->heso<<"x^"<<p->bac;
						}
					}
				}
			}
			if(p->next->next == 0 || p->heso == 0)
				cout<<"";
			else
				if(p->next->heso >0 || p->next->heso == 0)
					cout<<"+";
			p = p->next;

			if(p->bac == 0)
			{
				if(p->heso < 0)
					cout<<p->heso;
				else
				{
					if(p->heso > 0)
						cout<<"+"<<p->heso;
					else
						cout<<"";
				}
			}

		}
		cout<<endl;
	};

	void SetHeSo(int b, T h)
	{
		Node<T> *p = head;

		for(int i = head -> bac; i> b ;i--)
			p=p->next;
		p->heso = h;	
	};

	T Cal( T value)
	{
		Node<T> *p = head;
		int sum = 0;
		int i = head->bac;
		while(p != 0)
		{
			sum = sum + (p->heso)*pow(value,i);
			p=p->next;
			i--;
		}
		return sum;
	};

	Polynomial<T> operator * (T value)
	{
		Polynomial<T> p(head->bac);
		Node<T> *r = p.head;
		Node<T> *q = head;
		for(int i = head->bac; i>=0;i--)
		{
			r ->heso = q->heso * value;
			r = r->next;
			q = q->next;	
		}
		return p;
	};
};

#endif