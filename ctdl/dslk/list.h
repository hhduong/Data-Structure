#ifndef list_h
#define list_h
#include "node.h"
template <class T>
class List
{
private:
	Node<T> *head;
public:
	List()
	{
		head = 0;
	}
	List(T t, int Cout)
	{
		head = 0;
		for(int i=0;i<Cout;i++)
		{
			Add(t);
		}
	}
	List(List<T> l, int loop)
	{
		head = 0;
		for(int i=0;i<loop;i++)
		{
			Node<T> *p = l.head;
			while(p!=0)
			{
				Add(p->data);
				p = p->next;
			}
		}
	}
	List(List<T> l, int from, int to)
	{
		head = 0;
		Node<T> *p = l.head;
		for(int i=from;i<=to;i++)
			p = p->next;
		for(int i=from;i<=to;i++)
		{
			pushBack(p->data);
			p=p->next;
		}
	}

	void Add(T v)
	{
		Node<T> *n = new Node<T>;
		n->data = v;
		n->next = 0;
		if(head == 0)
			head = n;
		else
		{
			Node<T> *p=head;
			while(p->next != 0)
				p = p->next;
			p->next = n;
		}
	}
	void AddTop(T value)
	{
		Node<T> *n = new Node<T>;
		n->data = value;
		if(head==0)
		{
			head = n;
		}
		else
		{
			n->next = head;
			head = n;
		}
	}
	void Change(int pos, T value)
	{
		Node<T> *n = new Node<T>;
		n->data = value;
		Node<T> *p = head;
		for(int i=0;i<pos-1;i++)
		{
			p = p->next;
		}
		n->next = p->next;
		p->next = n;
		Delete(pos);

	}
	void PrintAll() const
	{
		Node<T> *p = head;
		while(p!=0)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
		cout<<endl;
	}

	void Swap(int pos1, int pos2)
	{
		Node<T> *Current1 = head;
		Node<T> *Current2 = head;
		for(int i=0;i<pos1;i++)
		{
			Current1 = Current1 -> next;
		}
		for(int i=0;i<pos2;i++)
		{
			Current2 = Current2 -> next;
		}
		T t;
		t = Current1->data;
		Current1->data = Current2->data;
		Current2->data = t;
	}
	int Count() const
	{
		
	}
	void Insert(int pos, int value)
	{
		Node<T> *n = new Node<T>;
		n->data = value;
		Node<T> *p = head;
		if(pos == 1)
		{
			AddTop(value);
		}
		else
		{
			for(int i=0;i<pos-2;i++)
			{
				p = p->next;
			}
			n->next = p->next;
			n->next = p;
		}
	}

	void Delete(int pos)
	{
		if(pos == 1)
		{
			Node<T> *q = head;
			head = head->next;
			delete q;
		}
		else
		{
			Node<T> *p = head;
			for(int i=1; i<pos-1;i++)
			{
				p = p->next;
			}
			Node<T> *q = p->next;
			p->next = p->next->next;
			delete q;
		}		
	}
	void DeleteByValue(T value)
	{
		Node<T> *p = head;
		if(head->data==value)
		{
			Node<T> *q = head;
			head = head->next;
			delete q;
		}
		else
		{
			while(p->next!=0)
			{
				if(p->next->data == value)
				{
					Node<T> *q = p->next;
					p->next = p->next->next;
					delete q;
				}
				else
					p=p->next;
			}
		}
	}
	void Delete(int pos1, int pos2)
	{
		for(int i=pos2-1;i>pos1;i--)
		{
			Delete(i);
		}
	}
	int Count(T value) const
	{
		
	}
	bool Seach(T value)
	{
		Node<T> *t = head;
		while(t->next!=0)
		{
			if(t->data == value)
			{
				return true;
				break;
			}
			t=t->next;
		}
		return false;
	}

	int SeachMax()
	{
		Node<T> *t = head;
		t = t->next;
		T maxx = t->data;
		while(t->next!=0)
		{
			t = t->next;
			if(t->data>maxx)
				maxx = t->data;
		}
		return maxx;	
	}

	void Sort_up_ascending()
	{
		Node<T> *p = head;
		while (p!=0)
		{
			Node<T> *q = p->next;
			while (q!= 0)
			{
				if (p->data > q->data)
				{
					T t = p->data;
					p->data = q->data;
					q->data = t;
				}
				q = q->next;
			}
			p = p->next;
		}
	}
	
	int SeachMin()
	{
		Node<T> *t = head;
		t = t->next;
		T minn = t->data;
		while(t->next!=0)
		{
			t = t->next;
			if(t->data<minn)
				minn = t->data;
		}
		return minn;	
	}
};
#endif