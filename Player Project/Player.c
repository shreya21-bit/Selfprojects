#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"player.h"
void storehardcoded(Player* arr)
{
	arr[0].jerseyno=8;
	strcpy(arr[0].name,"Virat Kohli");
	arr[0].no_ofmatches=10;
	arr[0].no_ofruns=126;
	arr[0].no_ofwickets=2;
	ctr++;
	
	arr[1].jerseyno=6;
	strcpy(arr[1].name,"Rohit Sharma");
	arr[1].no_ofmatches=20;
	arr[1].no_ofruns=256;
	arr[1].no_ofwickets=5;
	ctr++;
	
	arr[2].jerseyno=7;
	strcpy(arr[2].name,"Shubham Gill");
	arr[2].no_ofmatches=26;
	arr[2].no_ofruns=189;
	arr[2].no_ofwickets=4;
	ctr++;
	
	
}
void displayData(Player* arr)
{ 
	printf("\n Displaying Player Records:\n");
	int i;
	for(i=0;i<ctr;i++)
	{
		
		printf("\n Jersey number:%d   \t Name:%s   \t  Matches:%d   \t Runs:%d   \t Wickets:%d   ",
		arr[i].jerseyno,arr[i].name,arr[i].no_ofmatches,arr[i].no_ofruns,arr[i].no_ofwickets);
		
	}	
	printf("\n");
}
void storedata(Player* arr,int s)
{ 
	printf("\n Store The Data Of Player:-");
	char name;
	int i,jorseyno,no_ofmatch,no_ofruns,no_ofwickets;
	for(i=0;i<s;i++)
	{
		if(ctr!=s)
		{
			fflush(stdin);
			printf("\n Enter the Name Player:-");
			gets(arr[ctr].name);
			//scanf("%s",&arr[ctr].name);
		
			printf("Enter The JorseyNo. Of Player:");
			scanf("%d",&arr[ctr].jerseyno);
			
			fflush(stdin);
			printf("Enter The No. of Matches:");
			scanf("%d",&arr[ctr].no_ofmatches);
			
			printf("Enter The No. of Runs:");
			scanf("%d",&arr[ctr].no_ofruns);
			
			printf("Enter The No. of Wickets:");
			scanf("%d",&arr[ctr].no_ofwickets);
			
			ctr++;
		}
	}
}
void display1(Player* arr,int index)
{		
	
		printf("\n Display Details Of Single Player:-\n");
	    printf("\n Jersey number:%d\t Name:%s\t  Matches:%d\t Runs:%d\t Wickets:%d ",
		arr[index].jerseyno,arr[index].name,arr[index].no_ofmatches,arr[index].no_ofruns,arr[index].no_ofwickets);
	     
}
void search(Player* arr)
{       
  		printf("\n\t Two Options To Search  Player Details:");
  		printf("\n\t 1) Search By Jersey Number");
  		printf("\n\t 2) Search By Name");
  		printf("\n\tPlease Enter The Choice:");
  		int searchby,jren,index;
  		char Name[20];
  		fflush(stdin);
  		scanf("%d",&searchby);
 			if(searchby==1)
 			{
 				printf("\n\tEnter Jersey No:");
 				scanf("%d",&jren);
		    	index=searchByJerseyno(arr,jren);
		    }
		    else if(searchby==2)	
			{
				printf("Enter  Name To Search:");
				fflush(stdin);
				gets(Name);
				index=searchByName(arr,Name);	
			}    
				if(index==-1)
		    	printf("Sorry The Player not found...");
		    	else
		    	{
		    	printf("\n\tPlayer Found\n");
		    	display1(arr,index);
		    	}
}
int searchByJerseyno(Player* arr,int jer)
{
	int i;
	for(i=0;i<ctr;i++)
	{
		//printf("\n enter the jerseyno no. for search=");
		//scanf("%d",jerseyno==n);
		if(arr[i].jerseyno==jer)
		{
			return i;
		}
	}
	return -1;
}
int searchByName(Player* arr,char* str)
{
	int i;
	for(i=0;i<ctr;i++)
	{
		if(strcmp(arr[i].name,str)==0)
		{
			return i;
		}
	}
	return -1;
}
void addPlayer(Player* arr,int size)
{
	printf("\nAdd Player Deatils:-");
	if(ctr<size)
	{
		printf("\n Enter the Jorsey Number:-");
		scanf("%d",&arr[ctr].jerseyno);
		
		fflush(stdin);
		printf("\n Enter the Name:-");
		
		gets(arr[ctr].name);
		//scanf("%s",&arr[ctr].name);
		
		printf("\n Enter the No. of Matches:-   ");
		scanf("%d",&arr[ctr].no_ofmatches);
		
		printf("\n Enter the No. of Runs :-   ");
		scanf("%d",&arr[ctr].no_ofruns);
		
		printf("\n Enter the No. of Wickets :-   ");
		scanf("%d",&arr[ctr]. no_ofwickets);
		
		ctr++;
		
	}
	else
	{
		printf("\n*********************************Insufficinet Memory**********************************");
	}
}
void deletePlayer(Player* arr,int index)
{   int jren;
	printf("\n--------Enter Details To Delete The Player:--------");
	printf("\nEnter Jersey No:");
	scanf("%d",&jren);
	index=searchByJerseyno(arr,jren);
	if(index==-1)
	printf("\nSorry Player Not Found");
	else
    { 
	    display1(arr,index);
	    int n=ctr;
	    for(int i=index;i<n-1;i++)
    	{ 
        	arr[i]=arr[i+1];
		}
	ctr--;
        printf("\n*******************************Player Deleted Successfully...*****************************");
    }
}
void sortPlayers(Player* arr)
{ 
	int ch;
  	printf("\nHOW YOU WANT TO SORT PLAYER:");
	printf("\n1)BY JERSEY NO\n2)BY RUNS\n3)BY MATCHES\n4)BY WICKETS");
	printf("\nENTER YOUR CHOICE:");
	scanf("%d",&ch);
	switch(ch)
  	{
  	case 1:
  		{
  			for(int i=0;i<ctr;i++)
  			{   
			  	for(int j=i+1;j<ctr;j++)
  			   	{
			  
  					if((arr[i].jerseyno)>(arr[j].jerseyno))
  					{
				  
  					Player temp;
  					temp=arr[i];
  					arr[i]=arr[j];
  					arr[j]=temp;
			     }
		   	   }
			}
			printf("\n**********************Players sorted successsfully by jersey no.*******************");
			displayData(arr);
  			
		}
		break;
  	case 2:	
        {
  			for(int i=0;i<ctr;i++)
  			{   for(int j=i+1;j<ctr;j++)
  			   {
			  
  				if((arr[i].no_ofruns)>(arr[j].no_ofruns))
  				 {
				  
  					Player temp;
  					temp=arr[i];
  					arr[i]=arr[j];
  					arr[j]=temp;
			     }
		   	   }
			}
			printf("\n**********************Players sorted successsfully by total runs.***********************");
			displayData(arr);
  			
		}
		break;
	case 3:
		{
  			for(int i=0;i<ctr;i++)
  			{   for(int j=i+1;j<ctr;j++)
  			   {
			  
  				if((arr[i].no_ofmatches)>(arr[j].no_ofmatches))
  				 {
				  
  					Player temp;
  					temp=arr[i];
  					arr[i]=arr[j];
  					arr[j]=temp;
			     }
		   	   }
			}
			printf("*************************Players sorted successsfully by no of matches**************************");
			displayData(arr);
  			
		}
		break;
	case 4:
	  {
  			for(int i=0;i<ctr;i++)
  			{   for(int j=i+1;j<ctr;j++)
  			   {
			  
  				if((arr[i].no_ofwickets)>(arr[j].no_ofwickets))
  				 {
				  
  					Player temp;
  					temp=arr[i];
  					arr[i]=arr[j];
  					arr[j]=temp;
			     }
		   	   }
			}
			printf("******Players sorted successsfully by number of wickets.*****");
			displayData(arr);
  			
		}
		break;
		default:
		printf("ERROR....INVALID CHOICE....");
		break;  	
  }
}
void update(Player* arr)
{
	int jer;
	printf("\nEnter The Jersey No.you Want To Update ");
	scanf("%d",&jer);
	int c=searchByJerseyno(arr,jer);
	
	//printf("%d",c);
	if(c==-1)
		printf("The joursey no. not found");
	else
	{
		int updatechoice,index, matches,runs,wickets;
			printf("\nWhice Information You Want To Update:\n1)No Of Matches\n2)No Of Runs\n3)No Of Wickets\n");
			printf("\nEnter The Choice:");
			scanf("%d",&updatechoice);
			
			switch(updatechoice)
			{
				case 1:
					update_Matches(arr,c);
					//scanf("%d",&arr[index].no_ofmatches);
				break;
				case 2:	
					update_Runs(arr,c);
					//scanf("%d",&arr[index].no_ofruns);
				
				break;
				case 3:
					update_Wickets(arr,c);
					//scanf("%d",&arr[index].no_ofwickets);
				
				break;
				
				default:
					printf("\n\t Invalid Choice");
			}
	            printf("\n*****Information Update Successfully*****");
              	//display1(arr,index);
		}
				//updatePlayer(arr,s);
}
void update_Matches(Player*arr,int c)
{
	int matches;
	printf("\n\tEnter No Of Matches Of The Player:- ");
	scanf("%d",&matches);
		if(c<ctr)
			{
				//arr[c].no_ofmatches=matches;
				arr[c].no_ofmatches= matches;
				displayData(arr);
			}
}
void update_Runs(Player* arr,int c)
{ 
	int runs;
	printf("\n\tEnter No Of Runs Of The Player:- ");
		scanf("%d",&runs);
			if(c<ctr)
				{
					arr[c].no_ofruns=runs;
					displayData(arr);
				}
}
void update_Wickets(Player* arr,int c)
{
	int wickets;
	printf("\n\tEnter No Of Wickets Of The Player:- ");
	scanf("%d",&wickets);
		if(c<ctr)
		{
			arr[c].no_ofwickets=wickets;
			displayData(arr);
		}	
}