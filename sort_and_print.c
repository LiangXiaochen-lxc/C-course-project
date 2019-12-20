#include "struct.h"
#include <string.h>
#include <stdio.h>

extern char currentArea[];
extern Student nowStudent[];
extern int nowStudentNum;

void sortByName(Student students[], int mode, int num){
	int i, j;
	Student t;
	if (mode == 1) {
		for (i = 0; i < num-1; i++) {
			for(j = i+1; j < num; j++) {
				if(strcmp(students[i].name, students[j].name) > 0) {
					t = students[i];
					students[i] = students[j];
					students[j] = t;
				}
			}
		}
	} else {
		for (i = 0; i < num-1; i++){
			for(j = i+1; j<num; j++){
				if(strcmp(students[i].name, students[j].name) < 0){
					t = students[i];
					students[i] = students[j];
					students[j] = t;
				}
			}
		}
	}
}
 

void sortByScore(int subject, Student students[], int mode, int num){
	int i, j;
	Student t;
	if (mode == 1) {
		for (i = 0; i < num-1; i++){
			for(j = i+1; j < num; j++){
				if(students[i].score[subject] > students[j].score[subject]){
					t = students[i];
					students[i] = students[j];
					students[j] = t;
				}
			}
		}
	} else {
		for (i = 0; i < num-1; i++){
			for(j = i+1; j < num; j++){
				if(students[i].score[subject] < students[j].score[subject]){
					t = students[i];
					students[i] = students[j];
					students[j] = t;
				}
			}
		}
	}
}

void sortAndPrint(){
	print("---------------------");
	print("排序与输出功能");
	print("当前范围：");
	print(currentArea);
	printSortOption();
	int choice = getChoice(0, 3);
	if (choice == 0){
		return;
	}
	print("正序排序输入1 倒序排序输入0");
	int sortChoice = getChoice(0, 1);
	switch (choice){
		case 1:
			sortByName(nowStudent, sortChoice, nowStudentNum);
			break;
		case 2:
			print("根据第几科的成绩排序？");
			int socreChoice = getChoice(1, 10);
			socreChoice--;
			sortByScore(socreChoice, nowStudent, sortChoice, nowStudentNum);
			break;
		case 3:
			sortByScore(10, nowStudent, sortChoice, nowStudentNum);
			break;
	}
	int i, j;
	printStudent(nowStudent, nowStudentNum);
}

