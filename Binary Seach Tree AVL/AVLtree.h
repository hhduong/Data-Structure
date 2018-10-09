template <class T>
struct AvlNode
{
	int height; // chi so can bang
	int data;
	struct AvlNode<T> left;
	struct AvlNode<T> right;
};

template <class T>
class TreeAVL
{
private:
	AvlNode<T> *root;
	void AddChild(T n, Node<T> *root)
	{
		
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
		root->right = SingleRightRotate(root->right);
		return SingleLeftRotate(root);
	};

	Node<T>* RotateRL(Node<T>* &root) // quay kep right - left
	{
		root->left = SingleLeftRotate(root->left); // rotate left
		return SingleRightRotate(root); // After rotate right
	};

public:




};