#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Player
{
	int jerseyno;
	char name[20];
	int no_ofmatches;
	int no_ofruns;
	int no_ofwickets; 
}Player;     //nickname of structure

//decleration
void storehardcoded(Player*);
void storedata(Player*,int);
void displayData(Player*);
void search(Player*);
int searchByJerseyno(Player*,int);
int searchByName(Player*,char*);
void addPlayer(Player*,int);
void search(Player *);
void display1(Player*,int);
void deletePlayer(Player*,int);
void sortByNo_of_Matches(Player);
void update(Player*);
void update_Matches(Player*,int);
void update_Runs(Player*,int);
void update_Wickets(Player*,int);
void updatePlayer(Player*,int);
void sortPlayers(Player*);
//void sortByNo_of_Runs(Player*);
//void sortByNo_of_Wickets(Player*);

//search();

extern int ctr;

