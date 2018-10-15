#ifndef dictree
#define dictree
#include <string.h>
struct Node
{
	char ch;
	Node *child;
	Node *next;
};
class DicTree
{
private:
	Node *root;
	Node * SeachKiTu(char kt, Node *p) const
	{
		Node *q = p->child;
		while(q!=0)
		{
			if(q->ch == kt)
				return q;
			q =q ->next;
		}
		return 0;
	};

	Node * AddKiTu(char kt, Node *p)
	{
		Node *q = p->child;
		if(q == 0)
		{
			Node *con = new Node;
			con->ch = kt;
			con->child = 0;
			con->next = 0;
			p->child = con;
			return con;
		}
		else
		{
			while(q->ch != kt && q->next != 0)
				q = q->next;
			if(q->ch == kt)
				return q;
			else
			{
				Node *em = new Node;
				em->ch = kt;
				em->child = 0;
				em->next = 0;
				q->next = em;
				return em;
			}
		}
	};
public:
	DicTree()
	{
		root = new Node;
		root->child = 0;
		root->next = 0;
	};
	void Add(const char *s)
	{
		int len = strlen(s);
		Node * p = root;
		for(int i=0; i<len; i++)
		{
			p = AddKiTu(s[i],p);
		}
		Node *pe = new Node;
		pe->ch = '#';
		pe->child = 0;
		pe->next = 0;
		Node *q = p->child;
		if(q == 0)
		{
			p->child = pe;
		}
		else
		{
			while(q->ch != '#' && q->next != 0)
			{
				q = q->next;
			}
			if(q->next == 0)
				p->next = pe;
		}
	};
	bool Search(const char *tu) const
	{
		int len = strlen(tu);
		Node * p = root;
		for(int i=0; i<len; i++)
		{
			p = SeachKiTu(tu[i],p);
			if(p == 0)
				return false;
		}
		Node *q = p->child;
		while(q!=0)
		{
			if(q->ch == '#')
				return true;
			q =q ->next;
		}
		return false;
	};

};
#endif