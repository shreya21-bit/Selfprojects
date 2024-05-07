#include <stdio.h>
#include <stdlib.h>
#include"player.h"


int ctr;
void main() 
{
	//function call
	printf("\n*************************************-----------------------**************************");
	printf("\n*************************************Player Management Syste***************************");
	printf("\n*************************************-----------------------**************************");
	Player arr[50];
	int s,choice,index;
	printf("\n\n---------------------------Already Present Data Of Players------------------------------");
		storehardcoded(arr);
		displayData(arr);
	do{
			//printf("\n\t\t1)Hardcoded Data Of Players");
			printf("\n\t\t1)Store Players Data");
			printf("\n\t\t2)Display Players Data");
			printf("\n\t\t3)Search Player");
			printf("\n\t\t4)Delete Player");
			printf("\n\t\t5)Update Player Details");
			printf("\n\t\t6)Sort Players");
			printf("\n\t\t7)EXIT");
			
			printf("\n\t\tPlease Enter Your Choice:");
			scanf("%d",&choice);
			
			
		
			switch (choice)
			{ 
				//case 1:
				    
				    //storehardcoded(arr);
				    //displayData(arr);
				    //break;
				case 1:
					storedata(arr,2);
					
					break;
				case 2:
					displayData(arr);
					
				    break;
				case 3:
					search(arr);
				    displayData(arr);
					break;
				
				case 4:
					deletePlayer(arr,1);
				    displayData(arr);
				    break;
				
				case 5:
					update(arr);
					//displayData(arr);
					break;
				
				case 6:
					sortPlayers(arr);
					displayData(arr);
			     	break;
				case 7:
					printf("\n\tExiting The System.....\n\tThank You.....");
			     	exit(0);
			     	break;
						
				default:
				   printf("INVALID CHOICE....");
				   break;
				  system("cls");  	    
			}
	
   		} while(choice!=7);
}
