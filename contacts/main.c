#include <stdio.h>
#include <unistd.h>
#define _CRT_SECURE_NO_WARNINGS 1 
#include"Contact.h"//下面struct PeoInfo data[1000];需要用
//通讯录
//1.能够存放1000个人的信息，每个人的信息包含：名字，年龄，性别，电话，地址
//2.增加某人的信息
//3.删除某人的信息
//4.修改某人的信息
//5.查找某人的信息
//6.排序某人的信息
//通讯录.c--专门测试通讯录的模块    contact.h--类型定义，函数声明    contact.c--函数的实现
void menu()
{
    printf("********************************************\n");
    printf("******       1.添加联系人            *******\n");
    printf("******       2.删除联系人            *******\n");
    printf("******       3.查找联系人            *******\n");
    printf("******       4.修改联系人            *******\n");
    printf("******       5.显示所有联系人        *******\n");
    printf("******       6.按姓名排序所有联系人  *******\n");
    printf("******       0.退出                  *******\n");
    printf("********************************************\n");
}

int main()//1000个数据全部开辟在栈上，(过大,有时候不够,不应直接固定1000)
//动态内存开辟----用的时候再开辟
{
    int a;
    int input=0 ;
    //创建通讯录---在contact.h已创建，需要引用   头文件#include"contact.h"
    struct Contact con;//通讯录---con是通讯录，是结构体类型
    //初始化通讯录---会改变con,需要用指针,传址
    InitContact(&con);

    do//为了满足2-5的要求
    {
        menu();
        printf("请选择\n");
        a=input;
            rewind(stdin);
        scanf("%d", &input);  
        if(a==input)
        input=7;
        switch(input)
        {     //此时不用case1...用枚举类型,然后直接用ADD，可读性更高
        case ADD://增加人的信息
            AddContact(&con);//将局部变量con传给Add函数
                break;
        case DEL://删除
            DelContact(&con);
                    break;
                case SEARCH://查找
                    SearchContact(&con);
                    break;
                case MODIFY://修改
                    ModifyContact(&con);
                    break;
                case SHOW ://显示
                    ShowContact(&con);
                    sleep(1);
                    break;    
                case SORT://排序
                    PrintContact(&con);//可以传值，但是效率不高
                    sleep(1);
                    break;
                case EXIT://退出
                    printf("退出通讯录\n");
                    break;                   
                default:
                    printf("选择错误，重新选择\n");
                    sleep(1);
                    break;

        }
    } 
    while (input);
    return 0;
}
