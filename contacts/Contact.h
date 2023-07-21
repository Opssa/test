#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_NAME 20//目的：全局变量的define，一改20全改
#define MAX_SEX  5//目的：全局变量的define，一改10全改
#define MAX_TELE 12//带\0
#define MAX_ADDR 30
#define MAX 1000
//类型的定义：
typedef struct PeoInfo//通信录里的某个人的信息
//将struct放在此处因为总共1000个人，需要创建许多次，直接在.h中创建一次即可
{                 //不能用枚举，因为枚举同类型才可以,只能用结构体
    char name[MAX_NAME];
    char sex[MAX_SEX];
    int age;
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
}PeoInfo;//用PeopleInfo直接定义之后就可以不用struct PeoInfo
//通讯录----通信录里的信息，包括每个人，嵌套的有某个人的信息的结构体类型typedef struct PeoInfo

//枚举主函数内部
enum Option//枚举里面的变量一般都用大写
{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT,
};

//结构体的目的是存放和记录人的信息放一起
typedef struct Contact
{
    PeoInfo data[MAX];//存放添加进来的人的信息
    int sz;//记录当前通讯中有效信息的个数
}Contact;

//初始化函数
void InitContact(Contact* pc);//函数的声明--------函数的实现放.c文件
//增加人的信息
void AddContact(Contact*pc);
//打印联系人信息
void PrintContact(const Contact*pc);//const锁死pc,防止误操作修改指针
//删除联系人信息
void DelContact(Contact* pc);
//查找联系人信息
void SearchContact(Contact* pc);
//修改联系人信息
void ModifyContact(Contact* pc);
//展示联系人信息
void ShowContact(const struct Contact* pc);
//排序联系人信息
void SortContact(struct Contact* pc);
