#ifndef node_h
#define node_h
template <class T>
struct Node
{
	int bac;
	T heso;
	Node<T> *next;
};
#endif