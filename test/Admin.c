#include "Admin.h"
#include "Cwindow.h"
#include "Ctool.h"
#include <stdio.h>

void adminInit()
{
	WIN_T Admin = {3,3,25,23};
	CONTROL_T titleguan = {19,5,10,2,0,0,0,LABEL,"管理员界面"};
	CONTROL_T btntaizhuo = {19,9,8,3,0,0,0,BUTTON,"台桌管理"};
	CONTROL_T btncaipu = {19,12,8,3,0,0,0,BUTTON,"菜谱管理"};
	CONTROL_T btnrenyuan = {19,15,8,3,0,0,0,BUTTON,"人员管理"};
	CONTROL_T btnzhuxiao = {19,18,8,3,0,0,0,BUTTON,"注销"};
	CONTROL_T btntuichu = {19,21,8,3,0,0,0,BUTTON,"退出"};

	Admin.ctrlCount = addControl(titleguan,Admin.ctrlArr,Admin.ctrlCount);
	Admin.ctrlCount = addControl(btntaizhuo,Admin.ctrlArr,Admin.ctrlCount);
	Admin.ctrlCount = addControl(btncaipu,Admin.ctrlArr,Admin.ctrlCount);
	Admin.ctrlCount = addControl(btnrenyuan,Admin.ctrlArr,Admin.ctrlCount);
	Admin.ctrlCount = addControl(btnzhuxiao,Admin.ctrlArr,Admin.ctrlCount);
	Admin.ctrlCount = addControl(btntuichu,Admin.ctrlArr,Admin.ctrlCount);
	
	printf("控件个数，%d\n",Admin.ctrlCount);
	
	showWindow(Admin);
	Admin = winRun(Admin);
}