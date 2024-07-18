#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include <string>

using namespace std;

class Player {
public:
    string name;
    int runs=0;
    int fours=0;
    int sixes=0;
    int balls=0;

public:
     void getname()
		{
			getline(cin,name);
		}
};

#endif  // PLAYER_H
