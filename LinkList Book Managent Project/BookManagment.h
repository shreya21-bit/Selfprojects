#include"Book.h"
#include"Node.cpp"
#pragma once

template<class T>
class BookManagment
{
	Node<T>* start;
	
	public:
		BookManagment();
		void AddBook(T,int); //Book=T(template)
		void searchByBookId(int);
		void searchByBookName(const char*);
		void searchByAuthor(const char*);
		void searchByCategory(const char*);
		void updatePrice(int);
		void updateRating(int);
		void deleteBook(int);
		void sortPrice();
		void sortRating();
		void displayBook();
		~BookManagment();
};