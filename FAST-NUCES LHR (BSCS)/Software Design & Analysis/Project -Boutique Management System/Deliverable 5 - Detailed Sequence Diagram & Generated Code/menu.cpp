#include <iostream>
#include "myconsole.h"
#include "mygraphics.h"
#include <conio.h>
using namespace std;
int main()
{
	//COLORREF Black=RGB(0,0,0);
	//COLORREF White=RGB(255,255,255);
//	myLine(200,100,900,100,White);
//	_getch();
/*	bool exit=false;
	while(exit==false)
	{
		myDrawText(10,10,20,"Welcome to the Menu",Black,White);
		myDrawText(10,30,35,"Press p to print Traingle",Black,White);
		myDrawText(10,50,25,"Press x to Exit",Black,White);
	}
*/
	
	//* COLOR DECLARTIONS--------------------------------------------------------------
	COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);
	COLORREF Pink = RGB (255,182,193);
	COLORREF Red = RGB (255,0,0);
	COLORREF Grey= RGB (128,128,128);
	COLORREF Green= RGB (34,139,34);
	COLORREF Yellow RGB (255, 255, 0);
	
	int n;
	bool exit=false;
	while (exit==false)
	{
		myDrawText(310,60,200,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",White, Black);
		myDrawTextWithFont(330,100,35,"-- Welcome to S&J Boutique --",Pink, Grey);
		myDrawTextWithFont(380,160,35,"-> Browse Collection ",White, Grey);
		myDrawTextWithFont(400,220,35,"-> Login/Sign Up ",White,Grey);
		myDrawTextWithFont(410,280,35,"-> My Account ",White,Grey);
		myDrawTextWithFont(440,340,35,"-> FAQs ",White,Grey);
		myDrawTextWithFont(350,400,35,"-> Returns and Exchange ",White,Grey);
		myDrawTextWithFont(410,460,35,"-> Contact Us ",White,Grey);
		myDrawTextWithFont(390,520,35,"-> Store Location ",White,Grey);
		myDrawText(310,580,80,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",White, Black);
		cin>>n;
		ClearScreen();
	}

	system("pause");
	return 0;
}