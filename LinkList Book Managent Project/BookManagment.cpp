#include<iostream>
using namespace std;
#include<cstring>
#include<cstdio>
#include<fstream>
#include"Book.h"
#include"BookManagment.h"
#include"Node.h"

///////////////////////////////////////////////////////////
template<class T>
BookManagment<T>::BookManagment()
{
	start = NULL;
	
	int i=1;
	ifstream out("Book_data.bin", ios_base::binary);  //file handling
	if(out)
	{
		while(!out.eof())
		{
			T b1; //object of book
			out.read((char*) &b1, sizeof(b1));
			if(out.eof())  //end of file reach = exit(read operation close)
			{
				break;
			}
			AddBook(b1,i);
			i++;
		}
		out.close();
	}

//		Node<T>* p=start;
//		
//		while(p!=NULL)
//		{
//			T b1=p->getData();
//			out.read((char*) &b1, sizeof(b1));
//			p=p->getNext();		
//			
//			
//		}
//		
//		out.close();			
			
			
}
//////////////////////////////////////////////////////////
template<class T>
void BookManagment<T>::AddBook(T b1,int pos)
{
	Node<T>* temp= new Node<T>(b1); //book replace with <T>i.e template
	
	if(pos==1 || start==NULL)
	{
		temp->setNext(start);
		start=temp;
	}
	else
	{
		Node<T>* p=start;
		int i=1;
		while(i<pos-1 && p->getNext()!=NULL)
		{
			p=p->getNext();
			i++;
		}
		temp->setNext(p->getNext());
		p->setNext(temp);
	}
}
///////////////////////////////////////////////////////////
template<class T>
void BookManagment<T>::searchByBookId(int id)
{
	if(start == NULL)
	{
		cout<<"\nStack is Empty!!..";
		return;
	}
	else
	{
		Node<T>* p=start;
		
		while(p!=NULL)
		{
			if(p->getData().getBookId()==id)
			{
				p->getData().display();
				return;
			}
			p=p->getNext();
		}
		cout<<"\n"<<id<<" is not in Linklist";
	}
}
///////////////////////////////////////////////////////////
template<class T>
void BookManagment<T>::searchByBookName(const char* name)
{
	if(start == NULL)
	{
		cout<<"\nStack is Empty!!..";
		return;
	}
	else
	{
		Node<T>* p=start;
		while(p!=NULL)
		{
			if(strcasecmp(p->getData().getBookName(),name)==0)
			{
				p->getData().display();
				return;
			}
			p=p->getNext();
		}
		cout<<"\n"<<name<<" is not in Linklist";
	}
}
///////////////////////////////////////////////////////////
template<class T>
void BookManagment<T>::searchByAuthor(const char* author)
{
	if(start == NULL)
	{
		cout<<"\nStack is Empty!!..";
		return;
	}
	else
	{
		Node<T>* p=start;
		
		while(p!=NULL)
		{
			if(strcasecmp(p->getData().getAuthorName(),author)==0)
			{
				p->getData().display();
				return;
			}
			p=p->getNext();
		}
	}
}
///////////////////////////////////////////////////////////
template<class T>
void BookManagment<T>::searchByCategory(const char* cat)
{
	if(start == NULL)
	{
		cout<<"\nStack is Empty!!..";
		return;
	}
	else
	{
		Node<T>* p=start;
		
		while(p!=NULL)
		{
			if(strcasecmp(p->getData().getCategory(),cat)==0)
			{
				p->getData().display();
				return;
			}
			p=p->getNext();
		}
	}
}
///////////////////////////////////////////////////////////
template<class T>
void BookManagment<T>::updatePrice(int id)
{
	if(start == NULL)
	{
		cout<<"\nStack is Empty!!..";
		return;
	}
	else
	{
		Node<T>* p=start;
		while(p!=NULL)
		{
			if(p->getData().getBookId()==id)
			{
				double price;
				cout<<"\nEnter Updated Price of Book: ";
				cin>>price;
				Book b1=p->getData();
				b1.setPrice(price);
				p->setData(b1);
				cout<<"\nPrice Updated Successfully....";
				return;
			}
			p=p->getNext();
		}
		cout<<"\n Book Not Found!";
	}
}
///////////////////////////////////////////////////////////
template<class T>
void BookManagment<T>::updateRating(int id)
{
	if(start == NULL)
	{
		cout<<"\nStack is Empty!!..";
		return;
	}
	else
	{
		Node<T>* p=start;
		while(p!=NULL)
		{
			if(p->getData().getBookId()==id)
			{
				double rate;
				cout<<"\nEnter Updated Rating of Book: ";
				cin>>rate;
				Book b1=p->getData();
				b1.setRating (rate);
				p->setData(b1);
				cout<<"\nRating Updated Successfully....";
				return;
			}
			p=p->getNext();
		}
		cout<<"\n Book Not Found!";
	}
}
///////////////////////////////////////////////////////////
template<class T>
void BookManagment<T>::deleteBook(int id)
{
	if(start == NULL)
	{
		cout<<"\nList is Empty!";
		return;
	}
	
	if(start->getData().getBookId()==id)
	{
		Node<T>* p=start;
		start=start->getNext();
		delete p;
		return;
	}
	
	if(start->getNext() == NULL)
	{
		cout<<"\nBook Not Found!";
		return;
	}
	
	Node<T>* p=start;
	Book temp=start->getNext()->getData();
	
	while(temp.getBookId()!=id && p->getNext()->getNext()!=NULL)
	{
		p=p->getNext();
		temp=p->getNext()->getData();
	}
	if(temp.getBookId()==id)
	{
		Node<T>* q=p->getNext();
		p->setNext(q->getNext());
		delete q;
		return;
	}
	cout<<"\nBook Not Found!";
}
///////////////////////////////////////////////////////////
template<class T>
void BookManagment<T>::sortPrice()
{
	for(Node<T>* p=start ; p!=NULL ; p=p->getNext())
	{
		for(Node<T>* q=p->getNext() ; q!=NULL ; q=q->getNext())
		{
			if(p->getData().getPrice() < q->getData().getPrice())
			{
				Book temp=p->getData();
				p->setData(q->getData());
				q->setData(temp);
			}
		}
	}
	displayBook();
	
}
///////////////////////////////////////////////////////////
template<class T>
void BookManagment<T>::sortRating()
{
	for(Node<T>* p=start ; p!=NULL ; p=p->getNext())
	{
		for(Node<T>* q=p->getNext() ; q!=NULL ; q=q->getNext())
		{
			if(p->getData().getRating() < q->getData().getRating())
				{
					Book temp=p->getData();
					p->setData(q->getData());
					q->setData(temp);
				}
		}
	}
	displayBook();
}
///////////////////////////////////////////////////////////
template<class T>
void BookManagment<T>::displayBook()
{
	if(start == NULL)
	{
		cout<<"\nNo Book Details in LinkList";
	}
	else
	{
		Node<T>* p=start;
		while(p!=NULL)
		{
			p->getData().display();
			p=p->getNext();
		}
	}
}
///////////////////////////////////////////////////////////
template<class T>
BookManagment<T>::~BookManagment()
{
	Node<T>* p=start;
		
		ofstream out("Book_data.bin",ios_base :: binary);
		while(p!=NULL)
		{
			T b1=p->getData();
			out.write((char*)&b1,sizeof(b1));
			p=p->getNext();
		}
		out.close();
		p=start;
		while(start!=NULL)
		{
			start=start->getNext();
			delete p;
			p=start;
		}
		cout<<"\nAll Book Saved !!\n";
}
