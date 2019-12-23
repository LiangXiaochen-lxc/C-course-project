#include <stdio.h>
#include <string.h>
#include "struct.h"
//全局变量 
extern int studentNum;
extern int areaNum; 

/*
黄华映
从文件读取范围信息

fileName 文件名
area 文件的内容保存到这里

return 1成功 0找不到文件 
*/ 
int readC(char* fileName, Area area[]){
    int i;
    FILE* target = fopen(fileName, "r");//以r模式打开文件 
    if (target == NULL){//找不到名为fileName的文件 返回0 
        return 0;
    }
    fscanf(target, "%d", &areaNum);//读取范围总数 
    for (i = 0; i < areaNum; i++){//读取范围id和范围名 
        fscanf(target, "%d %s", &area[i].id, area[i].name);
    }
    fclose(target);//关闭文件 
    return 1;
}

/*
黄华映
从文件读取性别信息

fileName 文件名
sex 文件的内容保存到这里

return 1成功 0找不到文件 
*/ 
int readS(char* fileName, Sex sex[]){
    int i, num;
    FILE* target = fopen(fileName, "r");//以r模式打开文件 
    if (target == NULL){//找不到名为fileName的文件 返回0 
        return 0;
    }
    fscanf(target, "%d", &num);//读性别总数 
    for (i = 0; i < num; i++){//读性别id和性别名 
        fscanf(target, "%d%s", &sex[i].id, sex[i].name);
    }
    fclose(target);//关闭文件 
    return 1;
}

/*
黄华映
从文件读取学生信息

fileName 文件名
student 文件的内容保存到这里

return 1成功 0找不到文件 
*/ 
int readStu(char* fileName, Student student[]){
    int i, j;
    FILE* target = fopen(fileName, "r");//以r模式打开文件 
    if (target == NULL){//找不到名为fileName的文件 返回0 
        return 0;
    }
    fscanf(target, "%d", &studentNum);//读取学生总数 
    for (i = 0; i < studentNum; i++){//读学生信息 
        fscanf(target, "%d %s %d %d", &student[i].id,//读 学号 姓名 性别代码 学院代码 
               student[i].name, &student[i].sid, &student[i].aid);
        for (j = 0; j < 10; j++){//读10科成绩 
            fscanf(target, " %lf", &student[i].score[j]);
        }
    }
    fclose(target);//关闭文件 
    return 1;
}

/*
梁笑尘
将学生信息写到文件

fileName 目标文件名
student 要写到文件的学生信息
studentNum 要写到文件的学生个数 
*/ 
void writeStu(char* fileName, Student student[], int studentNum){
	int i, j;
	FILE* target = fopen(fileName, "w");//以w模式打开文件 
	fprintf(target, "%d\n", studentNum);//写学生总数 
	for (i = 0; i < studentNum; i++){//写学生信息 
        fprintf(target, "%d %s %d %d", student[i].id,//写 学号 姓名 性别代码 范围代码 
               student[i].name, student[i].sid, student[i].aid);
        for (j = 0; j < 10; j++){//写10课的成绩 
            fprintf(target, " %.2lf", student[i].score[j]);
        }
        fprintf(target, "\n");
    }
    fclose(target);//关闭文件 
}
