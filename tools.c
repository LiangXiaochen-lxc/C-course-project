#include <stdio.h>
#include "struct.h"

extern char currentArea[];
extern Area area[];
extern Sex sex[];

int getChoice(int min, int max){
    char input[2];
    do{
        gets(input);
    }while(input[0] < min+'0' || input[0] > max+'0' || input[1] != '\0');
    return input[0] - '0';
}
void print(char* target){
    printf("%s\n", target);
}

void welcome(){
    print("---------------------");
    print("学生成绩管理系统");
    print("梁笑尘 黄华映 马汶研 林萱仪");
}

void printMenu(){
    print("---------------------");
    print("主界面");
    print("当前范围：");
    print(currentArea);
    print("1 更换范围");
    print("2 排序并输出");
    print("3 查找、修改");
    print("4 密码修改");
    print("0 退出");
}

void printSortOption(){
	print("1 根据姓名排序");
	print("2 根据单科成绩排序");
	print("3 根据平均成绩排序");
	print("0 返回上一级");
}

void printFindOption(){
	print("1 根据学号查找");
	print("2 根据姓名查找");
	print("0 返回上一级"); 
}

void printArea(Area area[], int areaNum){
	int i; 
	print("0 全体");
    for (i = 0; i < areaNum; ++i) {
        printf("%d %s\n", i+1, area[i].name);
    }
}

void printStudent(Student nowStudent[], int studentNum){
	int i, j;
	printf("  学号   姓名 性别       学院 第一科 第二科 第三科 第四科 第五科 第六科 第七科 第八科 第九科 第十科 平均分\n"); 
	for (i = 0; i < studentNum; i++){
		printf("%6d %6s %4s %10s", nowStudent[i].id,
               nowStudent[i].name, sex[nowStudent[i].sid].name, area[nowStudent[i].aid-1].name);
        for (j = 0; j < 11; j++){
            printf(" %6.2lf", nowStudent[i].score[j]);
        }
        printf("\n");
	}
}
