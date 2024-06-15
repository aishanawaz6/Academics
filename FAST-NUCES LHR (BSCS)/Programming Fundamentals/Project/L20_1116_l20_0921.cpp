#include <iostream>
#include "mygraphics.h"
#include "myconsole.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;
void Bat(int&x1, int&x2, int&y1, int&y2,COLORREF White, COLORREF Black) {

	if (_kbhit())
	{
		int i=70;
	    char cl=_getch();
	if (cl==77) {
		if (x2<970){
			myLine (x1 , y1, x2, y2,Black);
	myLine (x1=x1+i, y1, x2=x2+i, y2,White);
		}
	}
	if (cl==75){
		if (x1>0){
		myLine (x1, y1, x2, y2,Black);	
	myLine (x1=x1-i, y1,x2= x2-i, y2,White);
	}
	}
	i=0;
	if (cl=='0')
	{
		ClearScreen();
		myDrawTextWithFont(400,200 ,40,"GAME OVER",White,Black);
		Sleep(100000);
	}

	}

}

void ballup30 (int&f,int&g,int&h,int&k,int &boundary) {
	COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);
int r=20;
double j=11.6;
		if (f<=950)
			{
				    myEllipse(f=f+r, g=g-j, h=h+r,k= k-j,White,White);
					Sleep(30);
					myEllipse(f,g, h,k,Black,Black);		
			}
	else
			boundary=1;
	
}
void balldown30(int&f,int&g, int&h , int&k,int&boundary) {
	COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);
	int i=20;
	double j=11.6;		
 if (k<=470)
			{
				myEllipse(f=f-i,g=g+j,h=h-i,k=k+j,White,White);
				Sleep(50);
				myEllipse(f,g,h,k,Black,Black);
			}			
			else 
				boundary=2;
}

void ballup90(int&f,int&g, int&h,int&k, int&boundary){
	COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);
	int i=10;
	
 if (g>=10)
 {
	myEllipse (f,g=g-i,h,k=k-i,White,White);
	Sleep(10);
	myEllipse (f,g,h,k,Black,Black); 
 }
			else
				boundary=5;
}
void balldown90(int&f,int&g,int&h,int&k,int &boundary){
	COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);
	int i=10;
	if (k<=470)
	{
	myEllipse (f,g=g+i,h,k=k+i,White,White);
	Sleep(10);
	myEllipse (f,g,h,k,Black,Black);
	}
	else
		boundary=2;


}
void ballup60 (int&f,int&g,int&h,int&k,int &boundary) {
	COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);
int r=20;
double j=34.6;
	
	if (g>=10) 
	        {
				    myEllipse(f=f+r, g=g-j, h=h+r,k= k-j,White,White);
					Sleep(30);
					myEllipse(f,g, h,k,Black,Black);
			}
			else
				boundary=6;
}
void balldown60(int&f,int&g, int&h , int&k,int&boundary) {
	COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);
	int i=20;
	double j=34.6;
			
  if (k<=470)
			{
				myEllipse(f=f-i,g=g+j,h=h-i,k=k+j,White,White);
				Sleep(50);
				myEllipse(f,g,h,k,Black,Black);
			}			
			else 
				boundary=2;
}
void ballup150 (int&f,int&g,int&h,int&k,int &boundary) {
	COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);	
int r=20;
double j=11.6;		
        if(f>=30)
                {
				    myEllipse(f=f-r, g=g-j, h=h-r,k= k-j,White,White);
					Sleep(30);
					myEllipse(f,g, h,k,Black,Black);	
                }
       else
        	boundary=3;
}
void balldown150 (int&f,int&g,int&h,int&k,int &boundary) {
	COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);
int r=20;
double j=11.6;

	if (k<=470)
			{
				    myEllipse(f=f+r, g=g+j, h=h+r,k= k+j,White,White);
					Sleep(30);
					myEllipse(f,g, h,k,Black,Black);	
			}
	else
		boundary=2;
	
}
void ballup120 (int&f,int&g,int&h,int&k,int &boundary) {
	COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);	
int r=20;
double j=34.6;
	if (f>=30)  
	         {
				    myEllipse(f=f-r, g=g-j, h=h-r,k= k-j,White,White);
					Sleep(30);
					myEllipse(f,g, h,k,Black,Black);
			}
	else
	boundary=4;	
}
void balldown120 (int&f,int&g,int&h,int&k,int &boundary) {
	COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);
	
int r=20;
						double j=34.6;
	if (k<=470)
			{
				    myEllipse(f=f+r, g=g+j, h=h+r,k= k+j,White,White);
					Sleep(30);
					myEllipse(f,g, h,k,Black,Black);			
			}
	else
			boundary=2;
	
}
void ballbounce(int&f,int&g,int&h,int&k,int&boundary,int&x1,int&x2,int&c,int&co,int&cou,int&coun,int&count,char&check) {
COLORREF White=RGB(255,255,255);
COLORREF Black = RGB (0,0,0);

if(f>=x1+243 && f<=x2 && c==0 && k>=465)
{
	ballup150(f,g,h,k,boundary);
    c++;
}
else	
	if (c>0)
	ballup150(f,g,h,k,boundary);
else
	if (f>=x1+183&&f<=x1+240&&co==0&& k>=465)
	{
	ballup120(f,g,h,k,boundary);
    co++;
	}
else
	if (co>0)
	ballup120(f,g,h,k,boundary);
else
	if (f>=x1+123&&f<=x1+180&&cou==0&& k>=465)
	{
	ballup90(f,g,h,k,boundary);
	cou++;
    }
else
	if (cou>0)
	ballup90(f,g,h,k,boundary);
else
	if (f>=x1+63&&f<=x1+120&&coun==0&& k>=465)
	{
    ballup60(f,g,h,k,boundary);
	coun++;
	}
else
    if (coun>0)
    ballup60(f,g,h,k,boundary);
else
    if (f>=x1&&f<=x1+60&&count==0&& k>=465)
    {
    ballup30(f,g,h,k,boundary);
    count++;
    }
else
	if (count>0&&g>=10)
    ballup30(f,g,h,k,boundary);
else
	check='F';
}

int main() {
	int x1 = 235, y1 = 470, x2 = 535, y2 = 470, i = 0;

	  srand(time(NULL));
	int arrayx[7][10];
	int arrayy[7][10];
	int bricksarray[7][10];
	for (int i=0;i<7;i++){
		for (int j=0;j<10;j++){
bricksarray[i][j]=0;
		}
	}
	for (int i=0;i<7;i++){
		for (int j=0;j<10;j++){
arrayx[i][j]=0;
		}
	}
	for (int i=0;i<7;i++){
		for (int j=0;j<10;j++){
arrayy[i][j]=0;
		}
	}
				
int row, col;
	
	
	//* COLOR DECLARTIONS--------------------------------------------------------------
	COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);
	COLORREF Pink = RGB (255,182,193);
	COLORREF Red = RGB (255,0,0);
	COLORREF Grey= RGB (128,128,128);
	COLORREF Green= RGB (34,139,34);
	COLORREF Yellow RGB (255, 255, 0);
	//*--------------------------------------------------------------------------------------
		int n;
			int score[10];
	bool exit=false;
	while (exit==false){
		//* MENU -----------------------------------------------------------------------------------------------------------
		myDrawText(280,60,80,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",White, Black);
	myDrawTextWithFont(330,100,35,"--  Welcome to the Menu  --",White, Black);
		myDrawTextWithFont(310,160,35,"-> To Start a New Game Enter 1 ",Green, White);
	myDrawTextWithFont(310,220,35,"-> To Load Saved Game Enter 2 ",Black,Yellow);
	 myDrawTextWithFont( 298,280,35,"-> To Show Score History Enter 3 ",Red,White);
	myDrawTextWithFont(380,340,35,"-> To Exit Enter 0 ",White,Grey);
		myDrawText(280,410,80,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",White, Black);
		cin>>n;
	ClearScreen();
	//*-----------------------------------------------------------------------------------------------------------------------

		if (n==1 || n==2) {

//* Lives , Score & Level details -----------------------------------------------------		
	OutputString(100,1,"LEVEL: 1");
	OutputString(100,2,"REMAINING LIVES: 3");
	OutputString(100,3,"YOUR SCORE: 0 ");
	
//--------------------------------------------------------------------
	//**Iniial Display (Bricks, BAT & BALL)----------------------------------------------------------------------------------------
	row=(rand()%4+4);
		for (int i=0,y=0;i<row && y<1000;i++,y=y+25)//* To control Rows of bricks
		{col=rand()%6+5;
		
			for (int j=0,x=0;j<col && x<1000;j++,x=x+75) //* TO control Coloumns of bricks
			{	
		
				for (int i=-15;i<15;i++)                     // Triangle Brick
				myLine(37.5,y-32,37.5+i,y-32-10,Red);

				
			
			myRect (x,y,x+75,y+25,Black,Pink);  // Pink simple brick
			arrayx[i][j]=x;
			 arrayy[i][j]=y;
			    for (int lame=0;lame<6;lame++) 
			    {
			    if ((i==rand() % 7 && j==rand() % 10))
				{
				myRect(x+10,y+5,x+10+55,y+5+13,Black,Grey ); // Grey small Rectangle brick 
				bricksarray[i][j]++;
			    }
				}  
			
			for(int lame=0;lame<8;lame++)
			{
			if (i==rand() % 7 && j==rand() % 10){
			myEllipse (x+20,y+5,x+40,y+5+13,Black,Green);   // Green circle brick
			if(bricksarray[i][j]==0)
				bricksarray[i][j]=2;
			}
			}
			for(int lame=0;lame<7;lame++)
			{
			if (i==rand() % 7&& j==rand()){
			myRect (x+25,y+5,x+25+20 ,y+5+15,Black,Yellow);  // Yellow small square Brick
			if(bricksarray[i][j]==0)
				bricksarray[i][j]=3;}
			}
		}

	}
		myLine(x1,y1,x2,y2,White); //BAT
			
	//*----------------------------------------------------------------------------------------------------------------------
		
int x1=235, y1=470,x2=535, y2=470,i=0; // Bat coordinates
	int f=370,g=448,h=390,k=468; // Ball coordinates
	 //-----COLOUR DECLERATIONS ---
	COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);
	//Initial display---------------
	myLine(x1,y1,x2,y2,White); 
	myEllipse(f,g,h,k,White,White);
	myEllipse(f,g,h,k,Black,Black);
	//-------------------------

	int boundary=0;// TO identify endpoint
	int c=0,co=0,cou=0,coun=0,count=0; // To make sure ball doesn't stop midway
	char check='T'; // To make sure game overs



	//-----------  Beginning of main loop that controls both Bat & Ball   -------------------
while (check!='F') {
	
		Bat(x1,x2,y1,y2,White,Black); // FOR BAT MOVEMENTS ALONE

		for (int i=0;i<7;i++) // For brick detection/ collision
		{
			for (int j=0;j<10;j++)
			{
		    if (  ( (k<=arrayy[i][j]+25) && (g>=arrayy[i][j]) ) && ( (h<=arrayx[i][j]+75) && (f>=arrayx[i][j]) ) )
				myRect(arrayx[i][j],arrayy[i][j],arrayx[i][j]+75,arrayy[i][j]+25,Black,Black);
			}
		}
//For BALL Movements ----------------------------------
		    if ( (f>x2 && k>y2) || (f<x1 && k>y2) )
            check='F';
	    	if (boundary==0){
	        ballup30(f,g,h,k,boundary);
			}
		    else
			    if (boundary==1)
	     	balldown30(f,g,h,k,boundary);
	        else
		        if (boundary==2)
		    ballbounce(f,g,h,k,boundary,x1,x2,c,co,cou,coun,count,check);
		    else
		    	if (boundary==3)
			{
				c=0;
				balldown150(f,g,h,k,boundary);
			}
			else
				if (boundary==4)
			{
				co=0;
				balldown120(f,g,h,k,boundary);
			}
			else
				if (boundary==5)
			{
				cou=0;
				balldown90(f,g,h,k,boundary);
			}
			else
				if (boundary==6)
			{
				coun=0;
				balldown60(f,g,h,k,boundary);
			}

					
	}	
//-------------------------------------------   MainloopEndsHere -----------------------------------------------------------
			//*-----------------------------------------------------------------------------------	 
ClearScreen();
myDrawTextWithFont(400,200,40,"GAME OVER",White,Black);
Sleep(1000);
	exit=true;		
		}
	
	else //* To show previous score details 
			if (n==3){
				int arr[10];
				ofstream file1;
				file1.open("gamescore.txt",ios::out);
				file1<<score;
				file1.close();
				ifstream file;
				file.open("gamescore.txt");
				for (int i=0;i<10;i++)
				file>>arr[i];
				cout<<"Your previous scores are as follows: "<<endl;
				file.close();
				for (int i=0;i<10;i++)
				cout<<"Score number "<<i+1<<" : "<<arr[i]<<endl;
				Sleep(5000);
				_getch();
			
			}
		else //* To EXIT
			if (n==0)
			exit=true;
		ClearScreen();

	}
	return 0;
}