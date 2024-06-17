#include "Ctool.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>

void gotoxy(int x,int y)
{
	HANDLE hout;
	COORD pos= {x,y};

	hout= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,pos);
}

void paintWindow(int startX,int startY,int width,int height)
{
	int i= 0;
	gotoxy(startX,startY);
	printf("┌");
	for (i=0;i<width-2;i++) {
	printf("-");
	}
	printf("┐");
	
	for (i=1;i<=height-1;i++) {
	gotoxy(startX,startY+i);
	printf("|");
	}
	for (i=1;i<=height-1;i++) {
	gotoxy(startX+width*2-3,startY+i);
	printf("|");
	}
	
	gotoxy(startX,startY+height-1);
	printf("└");
	for (i=0;i<width-2;i++) {
	printf("-");
	}
	printf("┘");
	gotoxy(startX,startX+height);
}

void glb_string(int maxLen,int inputType,int ips,char str[])
{
	char ch =0;
	int i =0;
	while(1) {
	ch =getch();
	if (ch=='r'&&i>0) {
	break;
	}

	switch(inputType) {

	case 0:
	if (ch>='0'&&ch<='9'&&i<maxLen) {
	if (ips==0) {
	putch('*');
	}
	else {
	putch(ch);
	}
	str[i++] =ch;
	}
	break;

	case 1:
	if (i<maxLen&&(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) {
	if (ips==0) {
	putch('*');
	}
	else {
	putch(ch);
	}
	break;

	case 2:
	if (i<maxLen&&(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')) {
	if (ips==0) {
	putch('*');
	}
	else {
	putch(ch);
	}
	str[i++] =ch;
	}
	break;
	
	default:
	break;
	}
	}
	}
}
int getkey()
{
	char key =0;
	key =getch();
	if (key==-32) {
	key =getch();
	switch(key) {
	case 72:
	return KEY_UP;
	case 80:
	return KEY_DOWN;
	case 75:
	return KEY_LEFT;
	case 77:
	return KEY_RIGHT;
	}
	}
	else if (key==13) {
	return KEY_ENTER;
	}
	else if (key==27) {
	return KEY_ESC;
	}
	return key;
}
