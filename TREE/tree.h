#include <limits.h>
#include <math.h>
template <class T>
struct Node
{
	int data;
	struct Node<T> *Left;
	struct Node<T> *Right;
};
template <class T>
class Tree //Binary Tree
{
private:
	Node<T> *root;
	void AddChild(T n, Node<T> *root)
	{
		Node<T> *p = new Node<T>; //khoi tao 1 node de them vao cay
		p->data = n;
		p->Left = NULL;
		p->Right = NULL;
		if(root == NULL)
		{
			root = p;
		}
		else
		{
			if(root->data > n)
			{
				if(root->Left != 0)
					AddChild(n, root->Left);
				else
				{
					root->Left = new Node<T>;
					root->Left->data = n;
					root->Left->Left = 0;
					root->Left->Right=0;
				}
			}
			else if (root->data < n)
			{
				if(root->Right != 0)
					AddChild(n,root->Right);
				else
				{
					root->Right = new Node<T>;
					root->Right->data = n;
					root->Right->Left = 0;
					root->Right->Right = 0;
				}
			}
		}	
	};
	void Add(T value1, T value2, Node<T> *&root)
	{
		if(root!=0)
		{
			if(Seach(value1))
			{
				if(value1 == root->data)
				{
					if(root->Left != 0 && root->Right != 0)
					{
						return;
					}
					else if(root->Left != 0)
					{
						root->Right = new Node<T>;
						root->Right->data = value2;
						root->Right->Left = 0;
						root->Right->Right = 0;
					}
					else
					{
						root->Left = new Node<T>;
						root->Left->data = value2;
						root->Left->Left = 0;
						root->Left->Right=0;		
					}
					/*Node<T> *n = new Node<T>;
					n->data = value2;
					n->Left = 0;
					n->Right = 0;
					if(root->Left == 0)
						root->Left = n;
					else if(root->Right == 0)
						root->Right = n;*/
				}
				else
				{	
					Add(value1,value2,root->Left);
					Add(value1,value2,root->Right);
				}
			}
		}
	};
	void InOrder(Node<T> *root)
	{
		//Neu cay con phan tu thi tiep tuc duyet
		if(root!=NULL)
		{
			cout<<root->data<<" ";//xuat du lieu trong node
			InOrder(root->Left);//duyet qua trai
			InOrder(root->Right);//duyet qua phai
		}
	};
	void PreOrder(Node<T> *root)
	{
		//Neu cay con phan tu thi tiep tuc duyet
		if(root!=NULL)
		{
			PreOrder(root->Left);//duyet qua trai
			cout<<root->data<<" ";//xuat du lieu trong node
			PreOrder(root->Right);//duyet qua phai
		}
	};
	void PostOrder(Node<T> *root)
	{
		//Neu cay con phan tu thi tiep tuc duyet
		if(root!=NULL)
		{
			PostOrder(root->Right);//duyet qua phai
			cout<<root->data<<" ";//xuat du lieu trong node
			PostOrder(root->Left);//duyet qua trai
		}
	};
	// Tim phan tu
	bool Seach(Node<T> *root, int value)
	{
		Node<T> *p = root;
		while(p!=NULL)
		{
			if(p->data == value) // phan tu can tim bang node goc => in ra node goc
				return p;
			else if(value<p->data) // phan tu can tim nho hon node goc => duyet ben nhanh trai 
				Seach(p->Left,value);
			else
				Seach(p->Right,value);; // phan tu can tim lon hon node goc => duyet ben nhanh phai
			return NULL; // Khong co tra ve NULL
		}
	};

	//Xuat cac node co 2 con
	void Node_have_2_leaf(Node<T> *root)
	{
		if(root!=NULL)
		{	
			if(root->Left != NULL && root->Right != NULL)
				cout<<root->data<<" ";
			Node_have_2_leaf(root->Left); // Duyet sang nhanh trai cua cay
			Node_have_2_leaf(root->Right);// Duyet sang nhanh phai cua cay
		}
	};

	//Xuat cac node co 1 con
	void Node_have_1_leaf(Node<T> *root)
	{
		if(root!=NULL)
		{
			if((root->Left != NULL && root->Right == NULL) || (root->Left == NULL && root->Right != NULL))
				cout<<root->data<<" ";
			Node_have_2_leaf(root->Left);// Duyet sang nhanh trai cua cay
			Node_have_2_leaf(root->Right);// Duyet sang nhanh phai cua cay
		}	
	};

	//Xuat cac node la
	void Node_leaf(Node<T> *root)
	{
		if(root!=NULL)
		{
			if(root->Left != NULL && root->Right != NULL)
				cout<<root->data<<" ";
			Node_have_2_leaf(root->Left);// Duyet sang nhanh trai cua cay
			Node_have_2_leaf(root->Right);// Duyet sang nhanh phai cua cay
		}
	};

	//So tang cua cay
	int Height(Node<T> *root)
	{
		if(root==NULL)
		{
			return 0;
		}
		else
			return 1 + max(Height(root->Left),Height(root->Right));
	};

	// dem so node
	void Cal_Node(Node<T> *root)
	{
		if(root == 0)
			return 0;
		else
			return 1+ Cal_Node(root->Left) + Cal_Node(root->Right);
	}
	int Max = INT_MIN; //Gan cho bien Max gia tri nho nhat cua kieu int
	int Seach_Max(Node<T> *root)
	{
		if(root!=NULL)
		{
			if(Max < root->data)
				Max = root->data; // Cap nhat lai gia tri cho max
			Seach_Max(root->Left);
			Seach_Max(root->Right);
		}
		return Max;
	};

public:
	Tree()
	{
		root = 0;
	};
	void AddChild(T value)
	{
		if(root == 0)
		{
			Node<T> *n = new Node<T>;
			n->data = value;
			n->Left = 0;
			n->Right = 0;
			root = n;
		}
		else
		{
			AddChild(value, root);
		}
	};

	void InOrder()
	{
		InOrder(root);
		cout<<endl;
	};

	void PreOrder()
	{
		PreOrder(root);
		cout<<endl;
	};

	void PostOrder()
	{
		PostOrder(root);
		cout<<endl;
	};
	bool Seach(T value)
	{
		return Seach(root,value);
	};
	void Node_have_2_leaf()
	{
		Node_have_2_leaf(root);
	};

	void Node_have_1_leaf()
	{
		Node_have_1_leaf(root);
	};

	void Node_leaf()
	{
		Node_leaf(root);
	};

	int Seach_Max()
	{
		return Seach_Max(root);
	};
	void Add(T value1, T value2)
	{
		Add(value1,value2,root);
	};

	void Cal_Node()
	{
		return Cal_Node(root);
	};

	int Height()
	{
		return Height(root);
	};
};

