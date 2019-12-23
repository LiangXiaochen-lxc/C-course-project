#include <stdio.h>
#include <string.h>
#include "struct.h"

extern char currentArea[];
extern Area area[];
extern Sex sex[];

/*
梁笑尘
获取用户输入的一个min到max之间的数 
*/ 
int getChoice(int min, int max){
    char input[2];
    do{
        gets(input);//
    }while(input[0] < min+'0' || input[0] > max+'0' || input[1] != '\0');//
    return input[0] - '0';//
}

/*
梁笑尘
输出一个字符串并换行 
*/ 
void print(char* target){
    printf("%s\n", target);//
}

/*
梁笑尘 
欢迎内容 
*/ 
void welcome(){
    print("---------------------");
    print("学生成绩管理系统");
    print("梁笑尘 黄华映 马汶研 林萱仪");
}

/*
梁笑尘 
主菜单 
*/ 
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

/*
梁笑尘 
排序选项 
*/ 
void printSortOption(){
	print("1 根据姓名排序");
	print("2 根据单科成绩排序");
	print("3 根据平均成绩排序");
	print("0 返回上一级");
}

/*
梁笑尘 
寻找选项 
*/ 
void printFindOption(){
	print("1 根据学号查找");
	print("2 根据姓名查找");
	print("0 返回上一级"); 
}

/*
梁笑尘 
输出范围 
*/ 
void printArea(Area area[], int areaNum){
	int i; 
	print("0 全体");//
    for (i = 0; i < areaNum; ++i) {//
        printf("%d %s\n", i+1, area[i].name);
    }
}

/*
梁笑尘 
输出学生信息 
*/ 
void printStudent(Student* nowStudent[], int studentNum){
	int i, j;
	print("____________________________________________________________________________________________________________"); 
	printf("|  学号|  姓名|性别|      学院|第一科|第二科|第三科|第四科|第五科|第六科|第七科|第八科|第九科|第十科|平均分|\n"); 
	for (i = 0; i < studentNum; i++){
		printf("|%6d|%6s|%4s|%10s", nowStudent[i]->id,//
               nowStudent[i]->name, sex[nowStudent[i]->sid].name, area[nowStudent[i]->aid-1].name);
        for (j = 0; j < 11; j++){
            printf("|%6.2lf", nowStudent[i]->score[j]);//
        }
        printf("|\n");
	}
}

/*
梁笑尘
加密 
*/
void encode(unsigned char* password){
	unsigned char encoded[100];
	int i, j;
	for (i = strlen(password)-1, j = 0; i >= 0; i--, j++){
		encoded[j] = password[i]+8;
	}
	strcpy(password, encoded);
}

/*
梁笑尘
解密 
*/ 
void decode(char* password){
	unsigned char decoded[100];
	int i, j;
	for (i = strlen(password)-1, j = 0; i >= 0; i--, j++){
		decoded[j] = password[i]-8;
	}
	strcpy(password, decoded);
}
