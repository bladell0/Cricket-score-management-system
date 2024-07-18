#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>
#include "player.h"

using namespace std;


class Scoreboard : public Player {
private:
    int player1=0;
	  int player2=1;
	  int totalruns=0;
	  int wickets=0;
	  static int overs;
	  static int totalballs;
	  int currentball=0;
	  int currentover=0;
	  int totalfours=0;
	  int totalsixes=0;
   	  int extras=0;
   	  int currentplayer=0;

public:
    Player players[11];
    void getovers()
		{
			system("Color 4F");
			cout<<"\nEnter Total overs for the Match: ";
			cin>>overs;
			totalballs=overs*6;
			cin.ignore(1,'\n');
		}
		
    void getplayernames()
	    {
	    	system("Color 4F");
	    for (int i=0;i<2;i++)
        	{
	    	cout<<"Enter Name of batsman "<<i+1<<" : ";
	    	players[i].getname();
	        }
		}
    void currentscore(int r,int wide)       
		{
			system("Color 4F");
			if (r!=7)
			system("cls");
			cout<<endl<<"\tCurrent Score: "<<totalruns<<" \\ "<<wickets<<" (";
			cout<<currentover<<"."<<currentball<< "/ "<<overs<<")"<<"\t\tExtras:"<<extras;
			if (currentover>=1)
			cout<<"\t\tRemaining Balls: "<<totalballs-(((currentover*6)+currentball)+wide)<<endl;
			else
			cout<<"\t\tRemaining Balls: "<<totalballs-((currentball)+wide)<<endl;
			cout<<"\t";
			for (int i=0;i<110;i++)
			{
				cout<<"-";
			}
			cout<<endl<<left<<setw(20)<<"\tPlayer Name"<<setw(20)<<"Runs"<<setw(20)<<"Balls Faced";
			cout<<"\tTotal Sixes: "<<totalsixes<<"\t\tTotal fours: "<<totalfours<<endl;
			cout<<"\t";
			for (int i=0;i<110;i++)
			{
				cout<<"-";
			}

			cout<<endl<<"\t"<<left<<setw(20)<<players[player1].name<<setw(20)<<players[player1].runs;
			cout<<setw(20)<<players[player1].balls<<endl;
			cout<<"\t"<<left<<setw(20)<<players[player2].name<<setw(20)<<players[player2].runs;
			cout<<setw(20)<<players[player2].balls<<endl;
			cout<<"\t";
			for (int i=0;i<110;i++)
			{
				cout<<"-";
			}
		}
    void calruns()
		{
			system("Color 4F");
			int r,wide=0;
			
		 	for (int i=0; i<totalballs; i++)
	        {
	        do{
	        	cout<<endl<<endl<<"BALL NO: "<<i+1<<" : "<<endl<<endl;
		        cout<<"Enter 0 for wide or No ball\n1 for a single\n2";
				cout<<" for double\n3 for triple\n4 for a four";
		        cout<<endl<<"5 for dot ball\n6 for a Six\n7 for wicket"<<endl<<endl;
		        cout<<"Ans: ";
				cin>>r;
				cin.ignore(1,'\n');
		    if(r<0 || r>7) 
		    {
            cout << "Invalid input. Please enter a valid number of runs (0-6)." << endl;
            }
			}while (r<0 || r>7);
			if (r==0)
			{
			totalruns+=1;	
			totalballs+=1;
			extras+=1;
			wide+=1;
			}
			if (r==1)
			{
			currentball=currentball+1;
			totalruns+=1;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=1;
			if (currentplayer==player1)
			currentplayer=player2;
			else if (currentplayer==player2)
			currentplayer=player1;
			}
			if (r==2)
			{
			currentball=currentball+1;
			totalruns+=2;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=2;
			}
			if (r==3)
			{
			currentball=currentball+1;
			totalruns+=3;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=3;
			if (currentplayer==player1)
			currentplayer=player2;
			else if (currentplayer==player2)
			currentplayer=player1;
			}
			if (r==4)
			{
			currentball=currentball+1;
			totalruns+=4;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=4;
			players[currentplayer].fours+=1;
			totalfours+=1;
			
			}
			if (r==5)
			{
			currentball=currentball+1;
			players[currentplayer].balls+=1;	
			}
			if (r==6)
			{
			currentball=currentball+1;
			totalruns+=6;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=6;
			players[currentplayer].sixes+=1;
			totalsixes+=1;
		    }
		    if (r==7)
		    {
		    currentball=currentball+1;
		    players[currentplayer].balls+=1;
		    wickets+=1;
		    cout<<endl<<"OUT!";
		    if (wickets<10)
		    {
		    playerstats();
		    cout<<endl<<"Enter name of player next player: ";
		    cin>>players[1+wickets].name;
		    cin.ignore(1,'\n');
		    
		    if (currentplayer==player1)
		    {
		    	player1=1+wickets;
		    	currentplayer=1+wickets;
			}
			else if (currentplayer==player2)
			{
				player2=1+wickets;
				currentplayer=1+wickets;
			}
		    }
		   	
		}
		    if (currentball==6)
			{
				if (currentplayer==player1)
				{
					currentplayer=player2;
				}
				else if (currentplayer==player2)
				{
					currentplayer=player1;
				}
				currentover+=1;
				currentball=0;
			}
			if (wickets>=10)
			{
             i=totalballs;
			}
			if (wickets<=10 && r!=7)
			{
            currentscore(r,wide);
            }
		
		}
	}
		
    void currentscore(Scoreboard inn1, int r,int wide,int previousx)
		{
			system("Color 4F");
			system("cls");
			cout<<"\n\t";
			cout<<endl<<"\tCurrent Score: "<<totalruns<<" \\ "<<wickets<<" ("<<currentover<<"."<<currentball<< "/ "<<overs<<")"<<"\t\tExtras:"<<extras;
			cout<<"\tTO WIN:"<<(inn1.target()+1)-totalruns<<"\tOFF: ";
			if (currentover<1)
			cout<<totalballs-(currentball+wide)<<endl;
			else
			cout<<totalballs-((currentover*6)+wide+currentball)<<endl;
			cout<<"\t";
			for (int i=0;i<100;i++)
			{
				cout<<"-";
			}
			cout<<"\n\tTotal sixes: "<<totalsixes<<"\t\tTotal fours: "<<totalfours<<"\t\tTarget:"<<inn1.target()+1<<endl;
			cout<<"\t";
			for (int i=0;i<100;i++)
			{
				cout<<"-";
			}
			cout<<endl<<"\t"<<left<<setw(20)<<"Player Name"<<setw(20)<<"Runs"<<setw(20)<<"Balls Faced"<<endl;
			cout<<"\t";
			for (int i=0;i<100;i++)
			{
				cout<<"-";
			}
			cout<<endl<<"\t"<<left<<setw(20)<<players[player1].name<<setw(20)<<players[player1].runs<<setw(20)<<players[player1].balls<<endl;
			cout<<"\t"<<left<<setw(20)<<players[player2].name<<setw(20)<<players[player2].runs<<setw(20)<<players[player2].balls<<endl;
			cout<<"\t";
			for (int i=0;i<100;i++)
			{
				cout<<"-";
			}
		}
    void calruns(Scoreboard inn1, int previousx)
		{
			totalballs-=previousx;
			system("Color 4F");
			int r,wide=0;
		 	for (int i=0; i<totalballs; i++)
	        {
	        do{
	        	cout<<endl<<endl<<"BALL NO: "<<i+1<<" : "<<endl<<endl;
		        cout<<"Enter 0 for wide or No ball\n1 for a single\n2 for double\n3 for triple\n4 for a four";
		        cout<<endl<<"5 for dot ball\n6 for a Six\n7 for wicket"<<endl<<endl;
		        cout<<"Ans: ";
				cin>>r;
				cin.ignore(1,'\n');
		    if(r<0 || r>7) 
		    {
            cout << "Invalid input. Please enter a valid number of runs (0-6)." << endl;
            }
			}while (r<0 || r>7);
			if (r==0)
			{
			totalruns+=1;	
			totalballs+=1;
			extras+=1;
			wide+=1;
			}
			if (r==1)
			{
			currentball=currentball+1;
			totalruns+=1;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=1;
			if (currentplayer==player1)
			currentplayer=player2;
			else if (currentplayer==player2)
			currentplayer=player1;
			}
			if (r==2)
			{
			currentball=currentball+1;
			totalruns+=2;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=2;
			}
			if (r==3)
			{
			currentball=currentball+1;
			totalruns+=3;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=3;
			if (currentplayer==player1)
			currentplayer=player2;
			else if (currentplayer==player2)
			currentplayer=player1;
			}
			if (r==4)
			{
			currentball=currentball+1;
			totalruns+=4;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=4;
			players[currentplayer].fours+=1;
			totalfours+=1;
			
			}
			if (r==5)
			{
			currentball=currentball+1;
			players[currentplayer].balls+=1;	
			}
			if (r==6)
			{
			currentball=currentball+1;
			totalruns+=6;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=6;
			players[currentplayer].sixes+=1;
			totalsixes+=1;
		    }
		    if (r==7)
		    {
		    currentball=currentball+1;
		    players[currentplayer].balls+=1;
		    wickets+=1;
		    cout<<endl<<"OUT!";
		    if (wickets<10)
		    {
		    playerstats();
		    cout<<endl<<"Enter name of player next player: ";
		    cin>>players[1+wickets].name;
		    cin.ignore(1,'\n');
		    
		    if (currentplayer==player1)
		    {
		    	player1=1+wickets;
		    	currentplayer=1+wickets;
			}
			else if (currentplayer==player2)
			{
				player2=1+wickets;
				currentplayer=1+wickets;
			}
		    }
		    	
			}
		    if (currentball==6)
			{
				if (currentplayer==player1)
				{
					currentplayer=player2;
				}
				else if (currentplayer==player2)
				{
					currentplayer=player1;
				}
				currentover+=1;
				currentball=0;
			}
	       	if (totalruns>inn1.totalruns)
	        {
	        	i=totalballs;
			}
			if (wickets>=10)
			{
                i=totalballs;
			}
			if (wickets<10 && r!=7)
			{
            currentscore(inn1,r,wide,previousx);
            }
		
		}
	}
    void playerstats()
		{
			system("Color 4F");
			cout<<endl<<"\n\tPLAYER STATS: "<<endl;
			cout<<"\n\t";
			for (int i=0;i<100;i++)
			{
				cout<<"-";
			}
			cout<<endl<<"\t"<<left<<setw(20)<<"Player Name"<<setw(20)<<"Runs";
			cout<<setw(20)<<"Balls Faced"<<setw(20);
			cout<<"Total fours"<<setw(20)<<"Total Sixes"<<endl;
			cout<<"\t";
			for (int i=0;i<100;i++)
			{
				cout<<"-";
			}
			cout<<endl<<"\t"<<left<<setw(20)<<players[currentplayer].name;
			cout<<setw(20)<<players[currentplayer].runs;
			cout<<setw(20)<<players[currentplayer].balls<<setw(20);
			cout<<players[currentplayer].fours<<setw(20);
			cout<<players[currentplayer].sixes<<endl;
			
		}
    int target()
		{
			return totalruns;
		}
    void writefile(string team)
		{
			system("Color 4F");
			ofstream fout;
			fout.open("Score.txt",ios::app);
			fout<<"\t\t\t\t"<<team<<" Innings Summary"<<endl;
			fout<<"\t";
			for (int i=0;i<100;i++)
			{
				fout<<"-";
			}
			fout<<endl<<"\tTotal Score: "<<totalruns<<" \\ "<<wickets<<" (";
			fout<<currentover<<"."<<currentball<<")"<<"\tTOTAL SIXES: "<<totalsixes;
			fout<<"\t\tTOTAL FOURS: "<<totalfours<<endl;
			fout<<"\t";
			for (int i=0;i<100;i++)
			{
				fout<<"-";
			}
			fout<<endl<<"\t"<<left<<setw(20)<<"Player Name"<<setw(20)<<"Runs";
			fout<<setw(20)<<"Balls Faced"<<setw(20);
			fout<<"Total fours"<<setw(20)<<"Total Sixes"<<endl;
			fout<<"\t";
			for (int i=0;i<100;i++)
			{
				fout<<"-";
			}
			if (wickets<=9)
			{
			for (int i=0;i<=wickets+1;i++)
			{
			fout<<endl<<"\t"<<left<<setw(20)<<players[i].name<<setw(20)<<players[i].runs;
			fout<<setw(20)<<players[i].balls<<setw(20)<<players[i].fours<<setw(20);
			fout<<players[i].sixes<<endl;
		}
		    }
		    else
		    {
		    for (int i=0;i<wickets+1;i++)
			{
			fout<<endl<<"\t"<<left<<setw(20)<<players[i].name<<setw(20)<<players[i].runs;
			fout<<setw(20)<<players[i].balls<<setw(20)<<players[i].fours<<setw(20);
			fout<<players[i].sixes<<endl;
		}
			}
		    fout<<"\n\n\t\tEXTRAS THIS INNINGS: "<<extras;
		    fout<<"\n\n\n";
		    
		}
    void teamfile(int toss)
		{
			system("Color 4F");
			int r,wide=0;
			string line;
			if (toss==1)
	    	{
			ifstream fin("team1.txt");
			for (int i=0;getline(fin,line);i++)
			{
			    players[i].name=line;
			}
			}
			else if (toss==2)
			{
			ifstream fin("team2.txt");	
			for (int i=0;getline(fin,line);i++)
			{
			    players[i].name=line;
			}
			}
			cout<<endl<<"First Player: "<<players[0].name;
			cout<<endl<<"second Player: "<<players[1].name;
		 	for (int i=0; i<totalballs; i++)
	        {
	        do{
	        	cout<<endl<<endl<<"BALL NO: "<<i+1<<" : "<<endl<<endl;
		        cout<<"Enter 0 for wide or No ball\n1 for a single\n2 for double\n3 for triple\n4 for a four";
		        cout<<endl<<"5 for dot ball\n6 for a Six\n7 for wicket"<<endl<<endl;
		        cout<<"Ans: ";
				cin>>r;
				cin.ignore(1,'\n');
		    if(r<0 || r>7) 
		    {
            cout << "Invalid input. Please enter a valid number of runs (0-6)." << endl;
            }
			}while (r<0 || r>7);
			if (r==0)
			{
			totalruns+=1;	
			totalballs+=1;
			extras+=1;
			wide+=1;
			}
			if (r==1)
			{
			currentball=currentball+1;
			totalruns+=1;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=1;
			if (currentplayer==player1)
			currentplayer=player2;
			else if (currentplayer==player2)
			currentplayer=player1;
			}
			if (r==2)
			{
			currentball=currentball+1;
			totalruns+=2;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=2;
			}
			if (r==3)
			{
			currentball=currentball+1;
			totalruns+=3;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=3;
			if (currentplayer==player1)
			currentplayer=player2;
			else if (currentplayer==player2)
			currentplayer=player1;
			}
			if (r==4)
			{
			currentball=currentball+1;
			totalruns+=4;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=4;
			players[currentplayer].fours+=1;
			totalfours+=1;
			
			}
			if (r==5)
			{
			currentball=currentball+1;
			players[currentplayer].balls+=1;	
			}
			if (r==6)
			{
			currentball=currentball+1;
			totalruns+=6;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=6;
			players[currentplayer].sixes+=1;
			totalsixes+=1;
		    }
		    if (r==7 && wickets>=9)
		    {
		    currentball=currentball+1;
		    players[currentplayer].balls+=1;
		    wickets=10;
		    cout<<endl<<"OUT!";
		    cout<<endl<<players[currentplayer].name<<" is OUT!";
		    i=totalballs+1000;
			}
		    else if (r==7 && wickets<9)
		    {
		    currentball=currentball+1;
		    players[currentplayer].balls+=1;
		    wickets+=1;
		    cout<<endl<<"OUT!";
		    {
		   	cout<<endl<<players[currentplayer].name<<" is OUT!";
		    playerstats();
		    cout<<endl<<"Next player is : "<<players[1+wickets].name<<endl;
		    cout<<"\n\nwickets:"<<wickets;
		    
		    if (currentplayer==player1)
		    {
		    	player1=1+wickets;
		    	currentplayer=1+wickets;
			}
			else if (currentplayer==player2)
			{
				player2=1+wickets;
				currentplayer=1+wickets;
			}
		    }
		    
		    	
			}
		    if (currentball==6)
			{
				if (currentplayer==player1)
				{
					currentplayer=player2;
				}
				else if (currentplayer==player2)
				{
					currentplayer=player1;
				}
				currentover+=1;
				currentball=0;
			}
			if (wickets<=9 && r!=7)
			{
            currentscore(r,wide);
            }
		
		}
	}
		void teamfile(Scoreboard inn1,int toss,int previousx)
		{
			totalballs-=previousx;
			system("Color 4F");
			int r,wide=0;
			string line;
		if (toss==1)
	   	{
			ifstream fin("team2.txt");
			for (int i=0;getline(fin,line);i++)
			{
			    players[i].name=line;
			}
		}
		else if (toss==2)
		{
			ifstream fin("team1.txt");	
			for (int i=0;getline(fin,line);i++)
			{
			    players[i].name=line;
			}
		}
		    cout<<endl<<"First Player: "<<players[0].name;
			cout<<endl<<"second Player: "<<players[1].name;
		 	for (int i=0; i<totalballs; i++)
	        {
	        do{
	        	cout<<endl<<endl<<"BALL NO: "<<i+1<<" : "<<endl<<endl;
		        cout<<"Enter 0 for wide or No ball\n1 for a single\n2 for double\n3 for triple\n4 for a four";
		        cout<<endl<<"5 for dot ball\n6 for a Six\n7 for wicket"<<endl<<endl;
		        cout<<"Ans: ";
				cin>>r;
				cin.ignore(1,'\n');
		    if(r<0 || r>7) 
		    {
            cout<<"Invalid input. Please enter a valid number of runs (0-6)." << endl;
            }
			}while (r<0 || r>7);
			if (r==0)
			{
			totalruns+=1;	
			totalballs+=1;
			extras+=1;
			wide+=1;
			}
			if (r==1)
			{
			currentball=currentball+1;
			totalruns+=1;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=1;
			if (currentplayer==player1)
			currentplayer=player2;
			else if (currentplayer==player2)
			currentplayer=player1;
			}
			if (r==2)
			{
			currentball=currentball+1;
			totalruns+=2;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=2;
			}
			if (r==3)
			{
			currentball=currentball+1;
			totalruns+=3;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=3;
			if (currentplayer==player1)
			currentplayer=player2;
			else if (currentplayer==player2)
			currentplayer=player1;
			}
			if (r==4)
			{
			currentball=currentball+1;
			totalruns+=4;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=4;
			players[currentplayer].fours+=1;
			totalfours+=1;
			
			}
			if (r==5)
			{
			currentball=currentball+1;
			players[currentplayer].balls+=1;	
			}
			if (r==6)
			{
			currentball=currentball+1;
			totalruns+=6;	
			players[currentplayer].balls+=1;
			players[currentplayer].runs+=6;
			players[currentplayer].sixes+=1;
			totalsixes+=1;
		    }
		    if (r==7 && wickets>=9)
		    {
		    currentball=currentball+1;
		    players[currentplayer].balls+=1;
		    wickets=10;
		    cout<<endl<<"OUT!";
		    cout<<endl<<players[currentplayer].name<<" is OUT!";
		    i=totalballs+1000;
		   	cout<<"\n\nwickets:"<<wickets;
			}
		    else if (r==7 && wickets<9)
		    {
		    currentball=currentball+1;
		    players[currentplayer].balls+=1;
		    wickets+=1;
		    cout<<endl<<"OUT!";
		    {
		   	cout<<endl<<players[currentplayer].name<<" is OUT!";
		    playerstats();
		    cout<<endl<<"Next player is : "<<players[1+wickets].name<<endl;
		    
		    if (currentplayer==player1)
		    {
		    	player1=1+wickets;
		    	currentplayer=1+wickets;
			}
			else if (currentplayer==player2)
			{
				player2=1+wickets;
				currentplayer=1+wickets;
			}
		    }
		    
		    	
			}
		    if (currentball==6)
			{
				if (currentplayer==player1)
				{
					currentplayer=player2;
				}
				else if (currentplayer==player2)
				{
					currentplayer=player1;
				}
				currentover+=1;
				currentball=0;
			}
			if (wickets<10 && r!=7)
			{
            currentscore(inn1,r,wide,previousx);
            }
		
		}
	}
	int p_extras()
	{
		return extras;
	}

};

#endif  // SCOREBOARD_H
