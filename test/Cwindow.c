#include "Cwindow.h"
#include "Ctool.h"
#include<conio.h>
#include<string.h>

int addControl(CONTROL_T ctrl,CONTROL_T ctrlArr[20],int ctrlCount)
{
	ctrlArr[ctrlCount++] = ctrl;
	return ctrlCount;
}

void showWindow(WIN_T win)
{
	int i = 0;
	paintWindow(win.startx,win.starty,win.width,win.height);
	for (i=0;i<win.ctrlCount;i++)
	{
		if (win.ctrlArr[i].ctrlType == LABEL)
		{
		gotoxy(win.ctrlArr[i].startx,win.ctrlArr[i].starty);
		puts(win.ctrlArr[i].content);
		}
		else
		{
		paintWindow(win.ctrlArr[i].startx-2,win.ctrlArr[i].starty-1,
		win.ctrlArr[i].width,win.ctrlArr[i].height);
		gotoxy(win.ctrlArr[i].startx,win.ctrlArr[i].starty);
		puts(win.ctrlArr[i].content);
		}
	}
	gotoxy(0,29);
}

WIN_T winRun(WIN_T win)
{
	int i = 0;
	int key = 0;
	for (i=0;i<win.ctrlCount;i++)
	{
		if (win.ctrlArr[i].ctrlType == EDIT
			||win.ctrlArr[i].ctrlType == BUTTON)
		{
		gotoxy(win.ctrlArr[i].startx,win.ctrlArr[i].starty);
		break;
		}
	}
	while (1)
	{
		key = getkey();
		switch(key)
		{
		case KEY_DOWN:
			i++;
			if (i==win.ctrlCount)
			{
				i=0;
			}
			for (;i<win.ctrlCount;i++)
			{
				if (win.ctrlArr[i].ctrlType == EDIT
					||win.ctrlArr[i].ctrlType == BUTTON )
				{
				gotoxy(win.ctrlArr[i].startx,
						win.ctrlArr[i].starty);
				break;
				}
			}
			break;
		case KEY_UP:
			i--;
			if (i==-1)
			{
				i = win.ctrlCount-1;
			}
			for (;i>0;i--)
			{
				if(win.ctrlArr[i].ctrlType == EDIT
					||win.ctrlArr[i].ctrlType == BUTTON)
				{
				gotoxy(win.ctrlArr[i].startx,
						win.ctrlArr[i].starty);
				break;
				}
				if (i==0)
				{
				i = win.ctrlCount;
				}
			}
			break;
		case KEY_ENTER:
			if (win.ctrlArr[i].ctrlType == BUTTON)
			{
			win.foucsIndex = i;
			return win;
			}
			break;
		default:
			if (win.ctrlArr[i].ctrlType == EDIT)
			{
			editKeyListen(win.ctrlArr[i],key,
					win.ctrlArr[i].content);
			}
			break;
		
		}
	}
}


void editKeyListen(CONTROL_T ctrl,char ch ,char content[])
{
	int i = strlen(content);
	switch(ctrl.inputType)
	{
	case 0:
		if (ch>='0'&&ch<='9'&&i<ctrl.maxLen)
		{
			if (ctrl.ips==0)
			{
			putch('*');
			}
			else
			{
			putch(ch);
			}
			content[i++] = ch;
		}
		break;
	case 1:
		if (i<ctrl.maxLen&&(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		{
			if (ctrl.ips==0)
			{
			putch('*');
			}
			else
			{
			putch(ch);
			}
			content[i++] = ch;
		}
		break;
	case 2:
		if (i<ctrl.maxLen&&(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')
			||(ch>='0'&&ch<='9'))
		{
			if (ctrl.ips==0)
			{
			putch('*');
			}
			else
			{
			putch(ch);
			}
			content[i++] = ch;
		}
		break;
	default:
		break;
	}
}
