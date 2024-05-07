#include <iostream>
using namespace std;
#include"BookManagment.cpp" // for template we have to include .cpp file

int main() 
{
	BookManagment <Book>bm1;
	int choice=0 , pos;
	
	do
	{
		cout<<"\n****************************BOOK MANAGMENT SYSTEM***********************************";
		cout<<"\n\t\t\t1.Display Book";
		cout<<"\n\t\t\t2.Add Book";
		cout<<"\n\t\t\t3.Search Book";
		cout<<"\n\t\t\t4.Update Book";
		cout<<"\n\t\t\t5.Delete Book";
		cout<<"\n\t\t\t6.Sorting Book";
		cout<<"\n\t\t\t7.Exit";
		
		cout<<"\nEnter Choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				{
					bm1.displayBook();
				}
				break;
			case 2:
				{
					int bId;
					char bName[60],aName[60], cat[60];
					double price,rating;
					
					cout<<"\nEnter Book Id: ";
					cin>>bId;
					
					fflush(stdin);
					cout<<"\nEnter Book Name:";
					gets(bName);
					
					cout<<"\nEnter Author Name:";
					gets(aName);
					
					cout<<"\nEnter Category:";
					gets(cat);
					
					fflush(stdin);
					cout<<"\nEnter Price:";
					cin>>price;
					
					cout<<"\nEnter Rating:";
					cin>>rating;
					
					Book b1(bId,bName,aName,cat,price,rating);
					
					cout<<"\nEnter Which position do you want to insert Book: ";
					cin>>pos;
					
					bm1.AddBook(b1,pos);
					
					cout<<"\nInserted Book Details At Given Position Succesfully!!!\n";
				}
				break;
			
			case 3:
				{
					cout<<"\n\t\t1.Search by Book ID\n\t\t2.Search by Book Name\n\t\t3.Search by Book Author name\n\t\t4.Search by Category\nEnter your choice: ";
					cin>>choice;
					
					
						switch(choice)
						{
							case 1:
								{
									int id;
									cout<<"\nEnter id of book which want to search: ";
									cin>>id;
									bm1.searchByBookId(id);
								}
								break;
								
							case 2:
								{
									char name[30];
									cout<<"\nEnter name of book which want to search: ";
									cin>>name;
									bm1.searchByBookName(name);
								}
								break;
							
							case 3:
								{
									char Author[30];
									cout<<"\Enter Author name to search book: ";
									cin>>Author;
									bm1.searchByAuthor(Author);
								}
							break;
							case 4:
								{
									char category[30];
									cout<<"\Enter category to search book: ";
									cin>>category;
									bm1.searchByCategory(category);
								}
							
						}
				}
				break;
			case 4:
				{
					cout<<"\n\t\t1.updatePrice"<<"\n\t\t2.updateRating"<<"\n\t\t3.Both";
					cout<<"\n Enter your choice: ";
					cin>>choice;
					
						switch(choice)
						{
							case 1:
								{
									int id;
									cout<<"\nEnter id of book which want to update: ";
									cin>>id;
									bm1.updatePrice(id);
								}
								break;
							
							case 2:
								{
									int id;
									cout<<"\nEnter id of book which want to update: ";
									cin>>id;
									bm1.updateRating(id);
									
								}
								break;
								
//							case 3:
//								{
//									int id;
//									cout<<"\nEnter id of book which want to update: ";
//									cin>>id;
//									bm.updateBoth(id);
//								}
									
				
						}
				}
				break;
			case 5:
				{
					int id;
					cout<<"\nEnter Book Id Want to Delete: ";
					cin>>id;
					bm1.deleteBook(id);
					cout<<"\nBook Deleted Successfully....";	
					bm1.displayBook();	
				}
				break;
			case 6:
				{
					int choice;
					cout<<"\n\t\t1.Sort By Price"<<"\n\t\t2.Sort By Rating";
					cout<<"\nEnter Your Choice: ";
					cin>>choice;
					
					switch(choice)
					{
						case 1:
							{
								bm1.sortPrice();
							}
							break;
						
						case 2:
							{
								bm1.sortRating();
							}
							break;
					}
						
				}
				break;
			case 7:
				{
					cout<<"\n-------------------- Exiting Program-------------------------\n";
				}
				break;
			default:
				{
					cout<<"\n------Please enter valid Choice!!!-------\n";
				}
				break;
		}
	}while(choice!=7);
	
	return 0;

}