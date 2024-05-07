#include"node.h"
#include"Book.h"
//////////////////////////////////////////
template <class T>
Node<T>::Node(T d) //book data= T d 
{
	data = d;
	next = NULL;
}
///////////////////////////////////////////
template <class T>
void Node<T>::setData(T d)
{
	data = d;
}
//////////////////////////////////////////
template <class T>
T Node<T>::getData() //return T means book return
{
	return this->data;
}
///////////////////////////////////////////
template <class T>
void Node<T>::setNext(Node<T> *nt)
{
	next = nt;
}
////////////////////////////////////////
template <class T>
Node<T> *Node<T>::getNext()
{
	return this->next;
}

