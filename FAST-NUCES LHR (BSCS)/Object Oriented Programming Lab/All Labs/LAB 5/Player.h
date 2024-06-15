#include <string>
class Player {

   char *TeamName;
   char *PlayerName;
   int numberofinnings;
   int numberofnotouts;
   int numberofscores;
   int *scoreList;


	public:
		Player ();
	
	void setTeamName(char *tname);
	void setPlayerName(char *pname);
	void setnumberofinnings(int noi);
	void setnumberofnotouts(int nono);
	void setnumberofscores(int nos);
	void setscorelist (int*sl,int n);

	char *getTeamName();
    char *getPlayerName();
	int   getnumberofinnings();
	int getnumberofnotouts();
    int getnumberofscores();
    int  *getscoreList(); 

	double average ();
	void print ();
	void Compare(Player object);


};