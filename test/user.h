#ifndef USER_H
#define USER_H
#define ADMIN 1
#define MANAGER 2
#define WAITER 3

typedef struct user_t
{
	int ID;
	char name[20];
	char pwd[20];
	int role;
}USER_T;

void printUserInfo(USER_T userArr[10]);

void addUser(USER_T newuser,USER_T userArr[10]);

#endif
