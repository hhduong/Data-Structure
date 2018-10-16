#include <iostream>
using namespace std;
const int SIZE = 100;
class Node
{
	int key;
	int data;
	Node(int key, int value)
	{
		this->key = key;
		this->data = value;
	}
	friend class HashTable;
};

class HashTable
{
private:
	Node **H; //khai bao mang
public:
	//Ham khoi tao hash table
	HashTable()
	{
		H = new Node*[SIZE];
		//Khoi tao tat ca cac gia tri ban dau bang null
		for(int i=0; i<SIZE; i++)
			H[i] = NULL;
	};

	int hashCode(int key)
	{
		return key%SIZE;
	};

	void Insert(int key, int value)
	{
		int hash = hashCode(key);
		while(H[hash] != NULL && H[hash]->key != key)
		{
			hash = hashCode(hash + 1);
		}
		if(H[hash] != NULL)
			delete H[hash];
		H[hash] = new Node(key,value); //them vao node tiep theo
	};
	void search(int key)
	{
		int hash = hashCode(key);
		while(H[hash] != NULL && H[hash]->key != key)
		{
			hash = hashCode(hash + 1);
		}
		if(H[hash] == NULL)
			cout<<"Khong co!!"<<endl;
		else
		{
			cout<<H[hash]->data<<endl;
		}
	};
	void Display()
	{
		for(int i=0;i<SIZE;i++)
		{
			if(H[i] != NULL)
				cout<<"("<<H[i]->key<<","<<H[i]->data<<")";
		}
		cout<<endl;
	};
	bool Delete(int key)
	{
		int hash = hashCode(key);
		while(H[hash] != 0)
		{
			if(H[hash]->key == key)
				break;
			hash = hashCode(hash+1);
		}
		if(H[hash] == NULL)
			return false;
		else
		{
			delete H[hash];
			return true;
		}
	};
};