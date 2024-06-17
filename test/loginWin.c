#include "loginWin.h"
#include "Cwindow.h"
#include "Ctool.h"
#include "user.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern USER_T userArr[10];
extern count;

void loginInit()
{
	char name[9] = {0};
	char pwd[7] = {0};
	int role = -2;
	
	WIN_T loginWin = {5,5,24,16};
	CONTROL_T title = {19,7,10,2,0,0,0,LABEL,"点菜系统"};
	CONTROL_T labName = {10,9,10,3,0,0,0,LABEL,"请输入账号: "};
	CONTROL_T labPwd = {10,12,10,3,0,0,0,LABEL,"请输入密码: "};
	CONTROL_T editName = {25,9,10,3,10,2,1,EDIT,""};
	CONTROL_T editPwd = {25,12,10,3,8,0,0,EDIT,""};
	CONTROL_T btnok = {10,15,8,3,0,0,0,BUTTON,"登录"};
	CONTROL_T btncancle = {26,15,8,3,0,0,0,BUTTON,"返回"};

	loginWin.ctrlCount = addControl(title,loginWin.ctrlArr,
						loginWin.ctrlCount);
	loginWin.ctrlCount = addControl(labName,loginWin.ctrlArr,
						loginWin.ctrlCount);
	loginWin.ctrlCount = addControl(labPwd,loginWin.ctrlArr,
						loginWin.ctrlCount);
	loginWin.ctrlCount = addControl(editName,loginWin.ctrlArr,
						loginWin.ctrlCount);
	loginWin.ctrlCount = addControl(editPwd,loginWin.ctrlArr,
						loginWin.ctrlCount);
	loginWin.ctrlCount = addControl(btnok,loginWin.ctrlArr,
						loginWin.ctrlCount);
	loginWin.ctrlCount = addControl(btncancle,loginWin.ctrlArr,
						loginWin.ctrlCount);
	printf("控件个数,%d\n",loginWin.ctrlCount);

	showWindow(loginWin);
	loginWin = winRun(loginWin);
	switch(loginWin.foucsIndex)
	{
	case 5:
		role = Jude(loginWin.ctrlArr[3].content,
				loginWin.ctrlArr[4].content,userArr);
		gotoxy(27,17);
		if (role==-1)
		{
			printf("losed\n");
		}
		else
		{
			printf("successfully\n");
			system("cls");
			switch(role)
			{
			case ADMIN:
				adminInit();
				break;
			default:
				break;
			}
		}
		break;
	case 6:
		printf("break\n");
		break;
	default:
		break;
	}
}

int Jude(char name[],char pwd[],USER_T userArr[])
{
	int i = 0;
	for (;i<count;i++)
	{
		if (strcmp(name,userArr[i].name)==0&&strcmp(pwd,userArr[i].pwd)==0)
		{
		return userArr[i].role;
		}
	}
	return -1;
}
