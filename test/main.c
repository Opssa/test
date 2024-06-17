#include <stdio.h>
#include <string.h>
#include "user.h"
#include "Admin.h"
#include "loginWin.h"
#include <windows.h>

int count = 3;

USER_T userArr[10]={
	{1001,"admin","123456",1},
	{1002,"manager","123456",2},
	{1003,"waiter","123456",3}
};

int main()
{	
	SetConsoleOutputCP(65001);
	USER_T newuser = {0};
	loginInit();
	return 0;
}
