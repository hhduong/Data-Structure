template <class T>
struct Node
{
	int height; // chi so can bang
	int data;
	Node<T> *left;
	Node<T> *right;
};

template <class T>
class TreeAVL
{
private:
	Node<T> *root;
	Node<T>* AddChild(T data, Node<T> *root)
	{
		if(root == NULL)
		{
			root = new Node<T>;
			root->data = data;
			root->height = 0;
			root->left = NULL;
			root->right = NULL;
		}
		else if(data < root->data)
		{
			root->left = AddChild(data, root->left);
			if(Height(root->left) - Height(root->right) == 2)
			{
				if(data < root->left->data)
					root = rotateLL(root);
				else
					root = RotateRL(root);
			}
		}
		else if(data >  root->data)
		{
			root->right = AddChild(data,root->right);
			if(Height(root->right) - Height(root->left)  == 2)
			{
				if(data > root->right->data)
					root = rotateRR(root);
				else
					root = rotateLR(root);
			}
		}
		root->height = max(Height(root->left), Height(root->right)) +1; // cap nhat la do can bang
		return root;
	};

	Node<T>* rotateLL(Node<T>* &root) // quay don left - left
	{
		Node<T>* u = root->left;
		root->left = u->right; // rotate
		u->right = root;
		// update heights
		root->height = max(Height(root->left), Height(root->right))+1;
		u->height = max(Height(u->left), root->height) +1;
		return u;
	};

	Node<T>* rotateRR(Node<T>* &root) //quay don right right
	{
		Node<T>* u = root->right; 
		root->right = u->left; // rotate
		u->left = root;
		// update heights
		root->height = max(Height(root->left), Height(root->right))+1; 
		u->height = max(Height(u->right), root->height) +1;
		return u;
	};

	Node<T>* rotateLR(Node<T>* &root) // quay kep left - right
	{
		root->right = rotateLL(root->right);
		return rotateRR(root);
	};

	Node<T>* RotateRL(Node<T>* &root) // quay kep right - left
	{
		root->left = rotateRR(root->left); // rotate left
		return rotateLL(root); // After rotate right
	};
	int Height(Node<T> *root)
	{
		return (root == NULL ? -1 : root->height);
		
	};
	void Inorder(Node<T> *root) const
	{
		if(root != NULL)
		{
			cout<<root->data<<" ";
			Inorder(root->left);
			Inorder(root->right);
		}
	};
	void Preorder(Node<T> *root) const
	{
		if(root != NULL)
		{
	        Preorder(root->left);
	        cout << root->data << " ";
	        Preorder(root->right);
	    }
	};

public:
	TreeAVL()
	{
		root = NULL;
	};
	void AddChild(T data)
	{
		root = AddChild(data,root);
	};
	void Inorder() const
	{
		Inorder(root);
		cout<<endl;
	};
	void Preorder() const
	{
		Preorder(root);
		cout<<endl;
	};



};