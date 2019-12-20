#include <stdio.h>
#include <string.h>
#include "struct.h"

extern int studentNum;
extern int areaNum; 

int readC(char* fileName, Area area[]){
    int i;
    FILE* target = fopen(fileName, "r");
    if (target == NULL){
        return 0;
    }
    fscanf(target, "%d", &areaNum);
    for (i = 0; i < areaNum; i++){
        fscanf(target, "%d %s", &area[i].id, area[i].name);
    }
    fclose(target);
    return 1;
}

int readS(char* fileName, Sex sex[]){
    int i, num;
    FILE* target = fopen(fileName, "r");
    if (target == NULL){
        return 0;
    }
    fscanf(target, "%d", &num);
    for (i = 0; i < num; i++){
        fscanf(target, "%d%s", &sex[i].id, sex[i].name);
    }
    fclose(target);
    return 1;
}

int readStu(char* fileName, Student student[]){
    int i, j;
    FILE* target = fopen(fileName, "r");
    if (target == NULL){
        return 0;
    }
    fscanf(target, "%d", &studentNum);
    for (i = 0; i < studentNum; i++){
        fscanf(target, "%d %s %d %d", &student[i].id,
               student[i].name, &student[i].sid, &student[i].aid);
        for (j = 0; j < 10; j++){
            fscanf(target, " %lf", &student[i].score[j]);
        }
    }
    fclose(target);
    return 1;
}
