#include <stdio.h>
#include "string.h"
//声明函数
//主菜单
void show_menu();
//录入
void record();
//查看
void show_score();
//新增
void add_new();
//排序
void sorting();
//搜索
void search_stu();
//修改
void modify_score();
//删除
void delete();
//统计
void statistics();
//退出系统
void bye();

//定义全局变量
//日期类型结构体
struct date
{
    int year;
    int month;
    int day;
};

//学生类型结构体，
//长度为100的结构体数组
struct stu{
    char name[30];
    char id[30];
    int yuwen;
    int shuxue;
    int yingyu;
    struct date birthday;
} student[100];

//已录入人数
int stu_num=0;

int main() {
    show_menu();
    return 0;
}


//主菜单
void show_menu()
{
    printf("\t┌────────────────欢迎使用学生成绩管理系统v2.0──────────┐\n");
    printf("\t│                                                  │\n");
    printf("\t│           （1）录入成绩                            │\n");
    printf("\t│           （2）查看成绩                            │\n");
    printf("\t│           （3）新增同学                            │\n");
    printf("\t│           （4）成绩排序                            │\n");
    printf("\t│           （5）搜索同学                            │\n");
    printf("\t│           （6）修改成绩                            │\n");
    printf("\t│           （7）删除信息                            │\n");
    printf("\t│           （8）统计信息                            │\n");
    printf("\t│                                                  │\n");
    printf("\t│           （0）退出系统                            │\n");
    printf("\t└──────────────────────────────────────────────────┘\n");
    printf("输入选择：0~8 \n");

    int choice;
    scanf("%d",&choice);

    switch (choice) {
        case 1:
            record();
            break;
        case 2:
            show_score();
            break;
        case 3:
            add_new();
            break;
        case 4:
            sorting();
            break;
        case 5:
            search_stu();
            break;
        case 6:
            modify_score();
            break;
        case 7:
            delete();
            break;
        case 8:
            statistics();
            break;
        case 0:
            bye();


    }
}

//录入
void record()
{
    printf("输入录入人数：\n");
    scanf("%d",&stu_num);
    if(stu_num>100)
    {
        //录入人数超过100
        printf("超过系统总人数，请重新输入\n");
        char ch;
        getc(ch);
    }else if(stu_num<1)
    {
        //录入人数小于1
        printf("录入错误\n");
        show_menu();
    }else
    {
        int i;
        for(i=0;i<stu_num;i++)
        {
            printf("录入第%d位同学的姓名：\n",i+1);
            scanf("%s",student[i].name);
            printf("录入%s同学的语文成绩：\n",student[i].name);
            scanf("%d",&student[i].yuwen);
            printf("录入%s同学的数学成绩：\n",student[i].name);
            scanf("%d",&student[i].shuxue);
            printf("录入%s同学的英语成绩：\n",student[i].name);
            scanf("%d",&student[i].yingyu);
            printf("输入%s同学的出生年份：\n",student[i].name);
            scanf("%d",&student[i].birthday.year);
            printf("输入%s同学的出生月份：\n",student[i].name);
            scanf("%d",&student[i].birthday.month);
            printf("输入%s同学的出生日：\n",student[i].name);
            scanf("%d",&student[i].birthday.day);
        }
    }


    show_menu();
}
//查看
void show_score1()
{
    int i;

}

void show_score()
{
    printf("\t┌───────────┬───────────┬───────────┬────────┬──────┬───────┐\n");
    printf("\t│ id\t\t│Name\t\t│Birthday\t│Chinese │Math \t│English│\n");
    int i;
    for(i=0;i<stu_num;i++)
    {
        printf("\t├───────────┼───────────┼───────────┼────────┼──────┼───────┤\n");
        printf("\t│%-11s│%-11s│%4d-%2d-%2d │%-8d│%-6d│%-7d│\n",student[i].id,student[i].name,student[i].birthday.year,student[i].birthday.month,student[i].birthday.day,student[i].yuwen,student[i].shuxue,student[i].yingyu);
    }
    printf("\t└───────────┴───────────┴───────────┴────────┴──────┴───────┘\n");
    show_menu();
}
//新增
void add_new()
{

    show_menu();
}
//排序
void sorting()
{
    show_menu();
}
//搜索
void search_stu()
{


    show_menu();
}
//修改
void modify_score()
{

    show_menu();
}

//删除信息
void delete()
{
    char del_name[30];
    printf("输入要删除的同学姓名：\n");
    scanf("%s",del_name);

    int i;
    int result = 0;//搜索到的人数
    for(i=0;i<stu_num;i++)
    {
        if(strcmp(student[i].name,del_name)==0)
        {
            result++; //搜索到的人数+1

            //删除数组中下标为1的元素
            //把第i+1个元素复制给第i个元素……把最后stu_num-1个元素赋值给stu_num-2个元素
            int j;
            for(j=i;j<stu_num-1;j++)
            {
                //把第结构体数组中第j+1个元素复制给第j个元素
                strcpy(student[j].name,student[j+1].name);
                student[j].yuwen = student[j+1].yuwen;
                student[j].shuxue = student[j+1].shuxue;
                student[j].yingyu = student[j+1].yingyu;
                student[j].birthday.year = student[j+1].birthday.year;
                student[j].birthday.month = student[j+1].birthday.month;
                student[j].birthday.day = student[j+1].birthday.day;

            }

            stu_num--; //最后一位同学已复制给倒数第二为同学，所以将下标-1

        }
    }
    if(result==0)
    {
        printf("未找到该位同学信息\n");
    }

    show_menu();
}

//统计信息
void statistics()
{

}

//退出系统
void bye()
{
    printf("Thank you! Bye bye!");
}