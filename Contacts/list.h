#ifndef list_h
#define list_h
#include <fstream>
#include "Node.h"
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
			addBack(5);
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
				addBack(p->Data);
				p = p->next;
			}
		}
	}

	List(List<T> l, int from, int to)
	{
		head = 0;
		Node<T> *p = l.head;
		for(int i =1;i<from;i++)
			p = p->next;
		for(int i=from;i<=to;i++)
		{
			pushBack(p->data);
			p=p->next;
		}
	}

	T GetAnItem(int pos)
	{
		if(pos-1 == 0)
			return head ->Data;
		else
		{
			Node<T> *p = head;
			for(int i = 1;i<pos-1;i++)
				p=p->next;
			return p->next->Data;
		}
	};

	void addBack(T value)
	{
		Node<T> *n = new Node<T>;
		n->Data = value;
		n->next = 0;
		if(head == 0)
		{
			head = n;
		}
		else
		{
			Node<T> *Current = head;
			while(Current->next != 0)
			{
				Current = Current -> next;
			}
			Current->next= n;
		}
	}
	void addTop(T value)
	{ 
		Node<T> *n = new Node<T>;
		n->Data = value;
	

		if(head == 0)
		{
			n->next = 0;
			head = n;
		}
		else
		{
			n->next = head;
			head = n;
		}
	}
	void Change(int pos,T value) // chen vao vi tri pos, roi xoa pos cu; 
	{
		Node<T> *p = head;
		for(int i = 0;i<pos-1;i++)
			p=p->next;
		p->Data = value;
	};

	void swap(int pos1, int pos2)
	{
		Node<T> *Current1 = head;
		Node<T> *Current2 = head;
		for(int i=0;i<pos1-1;i++)
		{
			Current1 = Current1 -> next;
		}

		for(int i=0;i<pos2-1;i++)
		{
			Current2 = Current2 -> next;
		}
		T t = Current1->Data;
		Current1->Data = Current2->Data;
		Current2->Data = t;
	}
	T seach(T a) const
	{
		
		Node<T> *Current  = head;
		while(Current->next!=0)
		{
			Current = Current -> next;
			if(Current->Data==a)
			{
				return Current->Data; 
			}
		}
	}

	T seachMin() const
	{
		Node<T> *Current = head;
		Current = Current -> next;
		T minn = Current->Data;
		while(Current->next!=0)
		{
			Current = Current -> next;
			if(Current->Data<minn)
				minn=Current->Data;
		}
		return minn;
	}

	T seachMax() const
	{
		Node<T> *Current = head;
		Current = Current -> next;
		T maxx = Current->Data;
		while(Current->next!=0)
		{
			Current = Current -> next;
			if(Current->Data>maxx)
				maxx=Current->Data;
		}
		return maxx;
	}

	void Insert(int pos, T value)
	{
		Node<T> *p = new Node<T>;
		p->Data = value;
		Node<T> *q = head;
		if(pos==1)
		{
			addTop(value);
		}
		else
		{
			for(int i=1;i<pos-1;i++)
			{
				q = q -> next;
			}
			p->next = q->next;
			q->next = p;
		}
	}

	void Delete() const
	{
		if(head == 0)
		{
			cout<<"Danh sach rong"<<endl;
		}
		else if(head->next==0)
		{
			Node<T> *Current = head;
			head = 0;
		}
		else
		{
			Node<T> *Current = head;
			while(Current->next->next!=0)
			{
				Current = Current->next;
			}
			Node<T> *n = Current->next;
			Current->next=0;
			delete n;
		}
	}
	void Delete(int pos) const
	{
		if(pos == 1)
		{
			Node<T> *q = head;
			head = head -> next;
			delete q; 
		}
		else
		{
			Node<T> *p = head;
			for(int i=1;i<pos-1;i++)
			{
				p = p -> next;
			}
			Node<T> *q = p->next;
			p->next = p ->next->next;
			delete q;
		}
	}

	void Display()
	{
		Node<T> *Current = head;
		int i=1;
		while(Current!=0)
		{
			cout<<i<<Current->Data<<endl;
			Current = Current -> next;
			i++;
		}
		cout<<endl;
	}

	int size()
	{
		Node<T> *t = head;
		int counting=1;
		while(t->next!=0)
		{
			t = t->next;
			counting++;
		}
		return counting;
	}

};
	

#endif