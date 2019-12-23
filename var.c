#include "struct.h"

char currentArea[100] = "全体";//当前范围 

Student student[5000];//所有学生信息 
Student* nowStudent[5000];//当前范围下所有学生信息 
Area area[100];//范围信息 
Sex sex[10];//性别信息 

int studentNum = 0;//学生总数 
int nowStudentNum = 0;//当前范围下学生数 
int areaNum = 0;//范围总数 
