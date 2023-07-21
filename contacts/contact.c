#define _CRT_SECURE_NO_WARNINGS 1 
#include"Contact.h"
void InitContact(Contact* pc)//函数的实现及初始化
{
    pc->sz = 0;//初始化       指针pc指向变量sz
    //memset()内存设置---你给的空间的每块内容都初始化成你想要的内容，以字节为单位
    memset(pc->data, 0, sizeof(pc->data));//引头文件#include<string.h>
        //data代表的是起始地址,0代表要初始化为0，第三个参数是要初始化多少字节
    
}
void AddContact(Contact* pc)
{
    if (pc->sz == MAX)//通讯录data放满了
    {
        printf("通讯录已满，无法添加\n");
        return;//void不需要带回值
    }
    //增加一个人的信息
    printf("请输入姓名\n");
    scanf("%s", pc->data[pc->sz].name);//name等本身就是地址，age是变量
    printf("请输入年龄\n");
    scanf("%d", &(pc->data[pc->sz].age));
    printf("请输入性别\n");
    scanf("%s", pc->data[pc->sz].sex);
    printf("请输入电话\n");
    scanf("%s", pc->data[pc->sz].tele);
    printf("请输入地址\n");
    scanf("%s", pc->data[pc->sz].addr);
    pc->sz++;
    printf("增加成功\n");

}
void PrintContact(const Contact* pc)
{
    int i = 0;
    //打印标题
    printf("%-20s\t %-5s\t %-5s\t %-12s\t %-20s\n", "名字", "年龄", "性别", "电话","地址");
    //-t表示左对齐
    //20s表示名字的长度是20个,目的是限制名字的长度统一.....
    //打印数据
    for (i = 0; i < pc->sz; i++)//pc->sz是个数
    {
        printf("%-20s\t %-5d\t %-5s\t %-12s\t %-20s\n",
            pc->data[i].name,
            pc->data[i].age,
            pc->data[i].sex,
            pc->data[i].tele,
            pc->data[i].addr);
    }    
    
}
static int FindByName(Contact* pc,char name[])//只是形参,接收
//static修饰函数时，只能在自己的原文件用，其他函数用不了
//int型，返回下标或者-1.Contact* pc指向通讯录
{
    int i=0;
    for (i = 0; i < pc->sz; i++)
    {
        if (strcmp(pc->data[i].name, name) == 0)//两个字符串比较
        {
            return i;//相等，就是找到，返回下标
        }
    }
    return -1;//找不到
}
void DelContact(Contact* pc)
{
    char name[MAX_NAME] = { 0 };
    //如果没有，直接跳出
    if (pc->sz == 0)
    {
        printf("通讯录为空，无需删除\n");
        return;
     }
    printf("请输入要删除人的名字\n");
    scanf("%s", name);
    //1.查找要删除的人(是不是有这个人，有的话，返回下标)
    int pos=FindByName(pc,name);
    if (pos == -1)
    {
        printf("要删除的人不存在\n");
        return;
    }
    else
    {
        //2.删除----往前面前进一个元素，就把前一个元素覆盖掉，即删除掉
        int i = 0;
        for (i = pos; i < pc->sz - 1; i++)
        {
            pc->data[i] = pc->data[i + 1];//把pc指向data的数组里下标为i的元素改为i+1
        }
        pc->sz - 1;
        printf("删除成功\n");
    }
}

void SearchContact(Contact* pc)
{
    char name[MAX_NAME] = { 0 };
    printf("请输入要查找联系人的姓名\n");
    scanf("%s", name);
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("要查找的人不存在\n");
        return;
    }
    else
    {
        printf("%-20s\t %-5s\t %-5s\t %-12s\t %-20s\n", "姓名", "年龄", "性别", "电话", "地址");
        //-t表示左对齐
        //20s表示名字的长度是20个,目的是限制名字的长度统一.....
        //打印数据
    
            printf("%-20s\t %-5d\t %-5s\t %-12s\t %-20s\n",
                pc->data[pos].name,//下标所对应的元素为pos,打印pos
                pc->data[pos].age,
                pc->data[pos].sex,
                pc->data[pos].tele,
                pc->data[pos].addr);
    }
}

void ModifyContact(Contact* pc)
{
    char name[MAX_NAME] = { 0 };
    printf("请输入要修改联系人的姓名\n");
    scanf("%s", name);
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("要修改的人不存在\n");
        return;
    }
    else
    {
        printf("请输入姓名\n");
        scanf("%s", pc->data[pos].name);//name等本身就是地址，age是变量
        printf("请输入年龄\n");
        scanf("%d", &(pc->data[pos].age));
        printf("请输入性别\n");
        scanf("%s", pc->data[pos].sex);
        printf("请输入电话\n");
        scanf("%s", pc->data[pos].tele);
        printf("请输入地址\n");
        scanf("%s", pc->data[pos].addr);
        printf("修改成功\n");
    }
}
void ShowContact(const struct Contact* pc)
{
    if (pc->sz == 0)
    {
        printf("通讯录为空\n");
    }
    else
    {
        int i = 0;
        printf("%-20s\t %-5s\t %-5s\t %-12s\t %-20s\n", "姓名", "年龄", "性别", "电话", "地址");
        for (i = 0; i < pc->sz; i++)
        {
            printf("%-20s\t %-5d\t %-5s\t %-12s\t %-20s\n",
                pc->data[i].name,
                pc->data[i].age,
                pc->data[i].sex,
                pc->data[i].tele,
                pc->data[i].addr);
        }
    }
}

void SortContact(struct Contact* pc)
{
    if (pc->sz <= 0)
    {
        printf("通讯录中没有联系人，请添加!\n");
    }
    int i = 0;
    int j = 0;
    for (i = 0; i < pc->sz - 1; i++)
    {
        for (j = 0; j < pc->sz - i - 1; j++)
        {
            if (strcmp(pc->data[j].name, (pc->data[j + 1]).name) > 0)
            {
                PeoInfo tmp;
                tmp = pc->data[j];
                pc->data[j] = pc->data[j + 1];
                pc->data[j + 1] = tmp;
            }
        }
        printf("排序成功！\n");
}
}
