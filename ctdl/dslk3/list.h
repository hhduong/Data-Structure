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

	void addBack(T value)
	{
		Node<T> *n = new Node<T>;
		n->data = value;
		n->next = 0;
		if(head==0)
		{
			head = n;
		}
		else
		{
			Node<T> *p = head;
			while(p->next!=0)
			{
				p=p->next;
			}
			p->next = n;

		}
	}

	void PrintAll() const
	{
		Node<T> *p = head;
		while(p!=0)
		{	
			cout<<p->data<<";";
			p=p->next;
		}
		cout<<endl;
	}
	void addTop(T value)
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
			p=p->next;
		}
		n->next = p->next;
		p->next = n;
		Delete(pos)
	}
	void swap(int pos1, int pos2)
	{
		Node<T> *Current1 = head;
		Node<T> *Current2 = head;
		for(int i=0;i<pos1;i++)
		{
			Current1=Current1->next;
		}
		for(int i=0;i<pos1;i++)
		{
			Current2=Current2->next;
		}
		T t = Current1->data;
		Current1->data = Current2->data;
		Current2->data = t;
	}
	void Delete(int pos)
	{
		if(pos==1)
		{
			Node<T> *q = head;
			head = head->next;
			delete q;
		}
		else
		{
			Node<T> *p = head;
			for(int i=0;i<pos-1;i++)
			{
				p=p->next;
			}
			Node<T> *q = p->next;
			p->next = p->next->next;
			delete q;
		}
	}
	void Insert(int pos, T value)
	{
		Node<T> *p = new Node<T>;
		p->data = value;
		Node<T> *q = head;
		if(pos==1)
		{
			p->next = head;
			head = p;
		}
		else
		{
			for(int i=0;i<pos-2;i++)
			{
				p=p->next;
			}
			p->next = q->next;
			p->next = q;
		}
	}
};