#include <stdio.h>
#include "struct.h"

extern Area area[];
extern Sex sex[];
extern Student student[];
extern Student* nowStudent[];
extern int nowStudentNum;
extern int studentNum;

/*
ÁºÐ¦³¾
×¼±¸¹¤×÷ 
*/ 
void preparing(){
	welcome();
    readC("C_Info.txt", area);
	readS("S_Info.txt", sex);
	readStu("Stu_Info.txt", student);
	int i, j;
	for (i = 0; i < studentNum; i++){
		double ave = 0;
		for (j = 0; j < 10; j++){
			ave += student[i].score[j];
		}
		ave /= 10;
		student[i].score[10] = ave;
		nowStudent[i] = &student[i];
	}
	nowStudentNum = studentNum;
}

/*
ÁºÐ¦³¾ 
Ö÷²Ëµ¥ 
*/ 
int menu(){
	printMenu();
	switch(getChoice(0,4)){
		case 1:
			changeArea();
			break;
		case 2:
			sortAndPrint();
			break;
		case 3:
			findAndUpdate();
			writeStu("Stu_Info.txt", student, studentNum);
			break;
		case 4:
			resetPassword();
			break;
		default:
			return 0;
	}
	return 1;
}

/*
ÁºÐ¦³¾
mainº¯Êý 
*/ 
int main(){
	preparing();
	while(!login());
	while(menu());
	return 0;
}
