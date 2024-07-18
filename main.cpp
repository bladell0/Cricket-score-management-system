#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "player.h"
#include "scoreboard.h"

using namespace std;

#include "player.h"
#include "scoreboard.h"


int Scoreboard::overs = 0;
int Scoreboard::totalballs = 0;

int main() {
	system("Color 4F");
	
	int toss;
	int decide,extras;
	string Team1,Team2;
	int num,manual;
	cout<<"\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t|          WELCOME TO THE CRICKET SCOREBOARD   |"<<endl;
    cout<<"\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t|                                              |"<<endl;
    cout<<"\t\t\t\t\t|     A SMALL PROGRAM TO KEEP RECORDS OF       |"<<endl;
    cout<<"\t\t\t\t\t|       OF YOUR LOCAL CRICKET MATCHES.         |"<<endl;
    cout<<"\t\t\t\t\t|         ENJOY THE GAME OF CRICKET!           |"<<endl;
    cout<<"\t\t\t\t\t|                                              |"<<endl;
    cout<<"\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n"<<endl;
    cout<<"Enter Name of Team 1: ";
	cin>>Team1;
	cout<<"Enter Name of Team 2: ";
	cin>>Team2;
	do{
	cout<<"Enter 1 if you want to play with built in teams in txt file, else press 2 for adding local teams:";
	cin>>decide;
	
	if (decide==1)
	{
		do{
			
	cout<<"Press 1 for toss, 2 to start game manually. ";
	cin>>num;	
	Scoreboard score1;
	Scoreboard score2;
	if (num==1)
	{
		srand(time(0));
		toss=(rand()%2+1);
	if (toss==1)
	{
    cout<<Team1<<" WON THE TOSS!";
    score1.getovers();	
	system("cls");
	cout<<endl<<"LET'S START THE GAME!"<<endl;
	score1.teamfile(toss);
    cout<<endl<<"THIS TEAM MADE: "<<score1.target()<<endl;
	cout<<"THE TARGET IS "<<score1.target()+1<<"!"<<endl;
    score1.writefile(Team1);
	ofstream fout;
	fout.open("Score.txt",ios::app);
	fout<<"\n\t\tTarget: "<<score1.target()+1;
    cout<<"A file named \"Score.txt\" has been created for a summary of innings"<<endl;
    cout<<endl<<"LET'S START THE NEXT INNINGS!"<<endl<<endl;

    score2.teamfile(score1,toss,score1.p_extras());
    score2.writefile(Team2);
    if (score2.target()>score1.target())
    {
    	cout<<endl<<Team2<<" WON!";
		fout<<endl<<"\t\t"<<Team2<<" WON!";
	}
	else if (score1.target()>score2.target())
	{
		cout<<endl<<Team1<<" WON!";
		fout<<endl<<"\t\t"<<Team1<<" WON!";
	}
	else
	{
		cout<<endl<<"\n\n\t\tMATCH TIED!"<<endl;
		fout<<endl<<"\t\tMATCH TIED!"<<endl;
	}
    cout<<endl<<"A file named \"Score.txt\" has been created for a summary of Complete Match"<<endl;
}
	else if (toss==2)
	{
    cout<<Team2<<" WON THE TOSS!";
    score2.getovers();
	system("cls");
	cout<<endl<<"LET'S START THE GAME!"<<endl;
    score2.teamfile(toss);
    cout<<endl<<"THIS TEAM MADE: "<<score2.target()<<endl;
	cout<<"THE TARGET IS "<<score2.target()+1<<"!"<<endl;
    score2.writefile(Team2);
	ofstream fout;
	fout.open("Score.txt",ios::app);
	fout<<"\t\tTarget: "<<score2.target()+1;
    cout<<"A file named \"Score.txt\" has been created for a summary of innings"<<endl;
    
    cout<<endl<<"LET'S START THE NEXT INNINGS!"<<endl<<endl;
	score1.teamfile(score2,toss,score2.p_extras());
    score1.writefile(Team1);
    if (score2.target()>score1.target())
    {
    	cout<<endl<<Team2<<" WON!";
		fout<<endl<<"\t\t"<<Team2<<" WON!";
	}
	else if (score1.target()>score2.target())
	{
		cout<<endl<<Team1<<" WON!";
		fout<<endl<<"\t\t"<<Team1<<" WON!";
	}
	else
	{
		cout<<endl<<"\n\n\t\tMATCH TIED!"<<endl;
		fout<<endl<<"\t\tMATCH TIED!"<<endl;
	}
    cout<<endl<<"A file named \"Score.txt\" has been created for a summary of Complete Match"<<endl;
	}
}
	else if (num==2)
		{


		cout<<"\nWhich Team will bat first (1/2)? : ";
		cin>>manual;
		if (manual==1)
	{
    score1.getovers();
	system("cls");
	cout<<endl<<"LET'S START THE GAME!"<<endl;
	score1.teamfile(toss);
    cout<<endl<<"THIS TEAM MADE: "<<score1.target()<<endl;
	cout<<"THE TARGET IS "<<score1.target()+1<<"!"<<endl;
    score1.writefile(Team1);
	ofstream fout;
	fout.open("Score.txt",ios::app);
	fout<<"\t\tTarget: "<<score1.target()+1;
    cout<<"A file named \"Score.txt\" has been created for a summary of innings"<<endl;
    
    cout<<endl<<"LET'S START THE NEXT INNINGS!"<<endl<<endl;

    system("cls");
    score2.teamfile(score1,toss,score1.p_extras());
    score2.writefile(Team2);
    if (score2.target()>score1.target())
    {
    	cout<<endl<<Team2<<" WON!";
		fout<<endl<<"\t\t"<<Team2<<" WON!";
	}
	else if (score1.target()>score2.target())
	{
		cout<<endl<<Team1<<" WON!";
		fout<<endl<<"\t\t"<<Team1<<" WON!";
	}
	else
	{
		cout<<endl<<"\n\n\t\tMATCH TIED!"<<endl;
		fout<<endl<<"\t\tMATCH TIED!"<<endl;
	}
    cout<<endl<<"A file named \"Score.txt\" has been created for a summary of Complete Match"<<endl;
	}
	else if (manual==2)
	{
	score2.getovers();
	score2.getplayernames();
    
    system("cls");
	cout<<endl<<"LET'S START THE GAME!"<<endl;
    score2.teamfile(toss);
    cout<<endl<<"THIS TEAM MADE: "<<score2.target()<<endl;
	cout<<"THE TARGET IS "<<score2.target()+1<<"!"<<endl;
    score2.writefile(Team2);
	ofstream fout;
	fout.open("Score.txt",ios::app);
	fout<<"\t\tTarget: "<<score2.target()+1;
    cout<<"A file named \"Score.txt\" has been created for a summary of innings"<<endl;
    
    cout<<endl<<"LET'S START THE NEXT INNINGS!"<<endl<<endl;
    system("cls");
	score1.teamfile(score2,toss,score2.p_extras());
    score1.writefile(Team1);
    if (score2.target()>score1.target())
    {
    	cout<<endl<<Team2<<" WON!";
		fout<<endl<<"\t\t"<<Team2<<" WON!";
	}
	else if (score1.target()>score2.target())
	{
		cout<<endl<<Team1<<" WON!";
		fout<<endl<<"\t\t"<<Team1<<" WON!";
	}
	else
	{
		cout<<endl<<"\n\n\t\tMATCH TIED!"<<endl;
		fout<<endl<<"\t\tMATCH TIED!"<<endl;
	}
    cout<<endl<<"A file named \"Score.txt\" has been created for a summary of Complete Match"<<endl;
	}
	}
	if (num!=1 &&num!=2)
	{
		cout<<"\n\nINVALID INPUT, PLEASE ENTER AGAIN!"<<endl;
	}
	}
	while(num!=1 &&num!=2);
}
			
	
	else if (decide==2)
	{
	
	
	cout<<"Press 1 for toss, 2 to start game manually. ";
	cin>>num;	
	Scoreboard score1;
	Scoreboard score2;
	if (num==1)
	{
		srand(time(0));
		toss=(rand()%2+1);
	if (toss==1)
	{
    cout<<Team1<<" WON THE TOSS!";
    score1.getovers();	
	score1.getplayernames();
	system("cls");
	cout<<endl<<"LET'S START THE GAME!"<<endl;
	score1.calruns();
    cout<<endl<<"THIS TEAM MADE: "<<score1.target()<<endl;
	cout<<"THE TARGET IS "<<score1.target()+1<<"!"<<endl;
    score1.writefile(Team1);
	ofstream fout;
	fout.open("Score.txt",ios::app);
	fout<<"\t\tTarget: "<<score1.target()+1;
    cout<<"A file named \"Score.txt\" has been created for a summary of innings"<<endl;
    
    cout<<endl<<"LET'S START THE NEXT INNINGS!"<<endl<<endl;
	score2.getplayernames();
    system("cls");

    score2.calruns(score1,score1.p_extras());
    score2.writefile(Team2);
    if (score2.target()>score1.target())
    {
    	cout<<endl<<Team2<<" WON!";
		fout<<endl<<"\t\t"<<Team2<<" WON!";
	}
	else if (score1.target()>score2.target())
	{
		cout<<endl<<Team1<<" WON!";
		fout<<endl<<"\t\t"<<Team1<<" WON!";
	}
	else
	{
		cout<<endl<<"\n\n\t\tMATCH TIED!"<<endl;
		fout<<endl<<"\t\tMATCH TIED!"<<endl;
	}
    cout<<endl<<"A file named \"Score.txt\" has been created for a summary of Complete Match"<<endl;
}
	else if (toss==2)
	{
    cout<<Team2<<" WON THE TOSS!";
    score2.getovers();
	score2.getplayernames();
	system("cls");
	cout<<endl<<"LET'S START THE GAME!"<<endl;
    score2.calruns();
    cout<<endl<<"THIS TEAM MADE: "<<score2.target()<<endl;
	cout<<"THE TARGET IS "<<score2.target()+1<<"!"<<endl;
    score2.writefile(Team2);
	ofstream fout;
	fout.open("Score.txt",ios::app);
	fout<<"\t\tTarget: "<<score2.target()+1;
    cout<<"A file named \"Score.txt\" has been created for a summary of innings"<<endl;
    
    cout<<endl<<"LET'S START THE NEXT INNINGS!"<<endl<<endl;
	score1.getplayernames();
    system("cls");
	score1.calruns(score2,score2.p_extras());
    score1.writefile(Team1);
    if (score2.target()>score1.target())
    {
    	cout<<endl<<Team2<<" WON!";
		fout<<endl<<"\t\t"<<Team2<<" WON!";
	}
	else if (score1.target()>score2.target())
	{
		cout<<endl<<Team1<<" WON!";
		fout<<endl<<"\t\t"<<Team1<<" WON!";
	}
	else
	{
		cout<<endl<<"\n\n\t\tMATCH TIED!"<<endl;
		fout<<endl<<"\t\tMATCH TIED!"<<endl;
	}
    cout<<endl<<"A file named \"Score.txt\" has been created for a summary of Complete Match"<<endl;
	}
}
	else if (num==2)
	{
		cout<<"\nWhich Team will bat first (1/2)? : ";
		cin>>manual;
		if (manual==1)
	{
    score1.getovers();
	score1.getplayernames();
	system("cls");
	cout<<endl<<"LET'S START THE GAME!"<<endl;
	score1.calruns();
    cout<<endl<<"THIS TEAM MADE: "<<score1.target()<<endl;
	cout<<"THE TARGET IS "<<score1.target()+1<<"!"<<endl;
    score1.writefile(Team1);
	ofstream fout;
	fout.open("Score.txt",ios::app);
	fout<<"\t\tTarget: "<<score1.target()+1;
    cout<<"A file named \"Score.txt\" has been created for a summary of innings"<<endl;
    
    cout<<endl<<"LET'S START THE NEXT INNINGS!"<<endl<<endl;
	score2.getplayernames();

    system("cls");
    score2.calruns(score1,score2.p_extras());
    score2.writefile(Team2);
    if (score2.target()>score1.target())
    {
    	cout<<endl<<Team2<<" WON!";
		fout<<endl<<"\t\t"<<Team2<<" WON!";
	}
	else if (score1.target()>score2.target())
	{
		cout<<endl<<Team1<<" WON!";
		fout<<endl<<"\t\t"<<Team1<<" WON!";
	}
	else
	{
		cout<<endl<<"\n\n\t\tMATCH TIED!"<<endl;
		fout<<endl<<"\t\tMATCH TIED!"<<endl;
	}
    cout<<endl<<"A file named \"Score.txt\" has been created for a summary of Complete Match"<<endl;
	}
	else if (manual==2)
	{
	score2.getovers();
	score2.getplayernames();
    
    system("cls");
	cout<<endl<<"LET'S START THE GAME!"<<endl;
    score2.calruns();
    cout<<endl<<"THIS TEAM MADE: "<<score2.target()<<endl;
	cout<<"THE TARGET IS "<<score2.target()+1<<"!"<<endl;
    score2.writefile(Team2);
	ofstream fout;
	fout.open("Score.txt",ios::app);
	fout<<"\t\tTarget: "<<score2.target()+1;
    cout<<"A file named \"Score.txt\" has been created for a summary of innings"<<endl;
    
    cout<<endl<<"LET'S START THE NEXT INNINGS!"<<endl<<endl;
	score1.getplayernames();
    system("cls");
	score1.calruns(score2,score2.p_extras());
    score1.writefile(Team1);
    if (score2.target()>score1.target())
    {
    	cout<<endl<<Team2<<" WON!";
		fout<<endl<<"\t\t"<<Team2<<" WON!";
	}
	else if (score1.target()>score2.target())
	{
		cout<<endl<<Team1<<" WON!";
		fout<<endl<<"\t\t"<<Team1<<" WON!";
	}
	else
	{
		cout<<endl<<"\n\n\t\tMATCH TIED!"<<endl;
		fout<<endl<<"\t\tMATCH TIED!"<<endl;
	}
    cout<<endl<<"A file named \"Score.txt\" has been created for a summary of Complete Match"<<endl;
	}
	}

}
if (decide!=1 && decide!=2)
{
	cout<<"\n\nINVALID INPUT PLEASE ENETER AGAIN!\n";
}
} while (decide!=1 && decide!=2);
return 0;
}

