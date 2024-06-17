#include "user.h"
#include <stdio.h>
#include <string.h>

extern count;
void printUserInfo(USER_T userArr[10])
{
	int i = 0;
	printf("%d\n",count);
	for (i=0;i<count;i++)
	{
		printf("%d\t%s\t%s\t",userArr[i].ID,userArr[i].name,
					userArr[i].pwd);
		switch(userArr[i].role)
		{
		case ADMIN:
			printf("admin\n");
			break;
		case MANAGER:
			printf("manager\n");
			break;
		case WAITER:
			printf("waiter\n");
			break;
		default:
			break;
		}
	}
}

void addUser(USER_T newuser,USER_T userArr[10])
{
	memcpy(&userArr[count++],&newuser,sizeof(USER_T));
}
