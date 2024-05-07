#include<iostream>
#include"Book.h"
#pragma once
template <class T>
class Node
{
	T data;  //T data= Book Data
	Node<T> *next;
	
	public:
		Node(T);//constructor para
		T getData();
		Node<T> *getNext();
		void setData(T);
		void setNext(Node *);
		
};
