#ifndef node_h
#define node_h

template <class T>
struct Node
{
	T Data;
	Node<T> *next;
};

#endif