#include<iostream>
#include"mygraphics.h"
#include "myconsole.h"
#include <conio.h>

int main () {
	COLORREF Black = RGB (0,0,0);
		COLORREF White = RGB (255,255,255);
bool exit= false;
while (exit==false) {
myDrawText(10,10,25,"Welcome to the Menu.",Black,White);
myDrawText(10,30,15,"Press p to print triangle",Black,White);
myDrawText(10,50,25,"Press h for print horizontally inverted triangle",Black,White);
myDrawText(10,70,25,"Press v for vertically inverted triangle",Black,White);
myDrawText(10,90,25,"Press l for line",Black,White);
myDrawText(10,110,25,"Press c for circle",Black,White);
myDrawText(10,130,25,"Press r for rectangle",Black,White);
myDrawText(10,150,25,"Press x to Exit",Black,White);
char ch =_getch();
if (ch=='p') {
int x1=200;
int y1=100;
int size=50;
for (int i=-size;i<size;i++) {
	myLine (x1+i,y1,x1,y1+100,White);
}
Sleep(2000);
	}
else
	if (ch=='h') {
int x1=200;
int y1=100;
int size=50;
for (int i=-size;i<1.5;i++) {
	myLine(x1,y1,x1+i,y1+100,White);
}
Sleep(2000);
	}
	else
		if (ch=='v') {
			int x1=200;
int y1=100;
int size=50;
for (int i=-size;i<size;i++) {
	myLine(x1,y1,x1+i,y1-100,White);
} 
Sleep(2000);
		}
		else
			if (ch=='l') {
				myLine (0,480,1000,0,White);
				Sleep(2000);
			}
			else 
				if (ch=='c') {
						COLORREF Red = RGB (255,000,000);
	myEllipse (20,10,100,60,White,Red);
	Sleep(2000); }

				else
					if (ch=='r')
					{
							COLORREF SkyBlue = RGB (135,206,235);
	myRect (750,50,958,150,White,SkyBlue);
	Sleep(2000); }

else
	if (ch=='x')
		exit=true;
ClearScreen();
}
return 0;
}