#pragma once
class Book
{
	int bookId;
	char bookName[60];
	char authorName[60];
	char category[60];
	double price;
	double rating;
	
	public:
		Book();
		Book(int,const char*,const char*,const char*,double,double);
		void setBookId(int);
		int getBookId();
		void setBookName(const char*);
		const char* getBookName();
		void setAuthorName(const char*);
		const char* getAuthorName();
		void setCategory(const char*);
		const char* getCategory();
		void setPrice(double);
		double getPrice();
		void setRating(double);
		double getRating();
		void display();
};