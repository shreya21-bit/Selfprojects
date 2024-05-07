#include<iostream>
using namespace std;
#include<cstring>
#include<cstdio>
#include"Book.h"

//////////////////////////////////////////////////////////////
Book::Book()
{
	this->bookId=0;
	strcpy(this->bookName,"Not Given");
	strcpy(this->authorName,"Not Given");
	strcpy(this->category,"Not Given");
	this->price=0;
	this->rating=0;
}
////////////////////////////////////////////////////////////////
Book::Book(int i,const char* nm1,const char* nm2,const char* nm3,double p,double r)
{
	this->bookId=i;
	strcpy(this->bookName,nm1);
	strcpy(this->authorName,nm2);
	strcpy(this->category,nm3);
	this->price=p;
	this->rating=r;
}
////////////////////////////////////////////////////////////////////
void Book::setBookId(int i)
{
	this->bookId=i;
}
int Book::getBookId()
{
	return this->bookId;
}
void Book::setBookName(const char* bName)
{
	strcpy(this->bookName,bName);
}
const char* Book::getBookName()
{
	return this->bookName;
}
void Book::setAuthorName(const char* aName)
{
	strcpy(this->authorName,aName);
}
const char* Book::getAuthorName()
{
	return this->authorName;
}
void Book::setCategory(const char* cat)
{
	strcpy(this->category,cat);
}
const char* Book::getCategory()
{
	return this->category;
}
void Book::setPrice(double price)
{
	this->price=price;
}
double Book::getPrice()
{
	return this->price;
}
void Book::setRating(double rating)
{
	this->rating=rating;
}
double Book::getRating()
{
	return this->rating;
}
/////////////////////////////////////////////////////////////
void Book::display()
{
	cout<<"\n+----------------------------------------------------------------------------------------------------------------------+\n";
	cout<<"|\tBook ID"<<"\t|\t"<<"Book Name"<<"\t|\t"<<"Author name"<<"\t|\t"<<"Category"<<"\t|\t"<<"Price"<<"\t|\t"<<"Rating"<<"\t|\t";
	cout<<"\n+----------------------------------------------------------------------------------------------------------------------+";
	cout<<"\n|\t"<<this->bookId;
	cout<<"\t|\t"<<this->bookName;
	cout<<"\t\t|\t"<<this->authorName;
	cout<<"\t|\t"<<this->category;
	cout<<"\t\t|\t"<<this->price;
	cout<<"\t|\t"<<this->rating<<"\t|";	
	cout<<"\n+----------------------------------------------------------------------------------------------------------------------+\n";

}