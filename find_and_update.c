#include "struct.h"
#include <stdio.h>
#include <string.h>
extern char currentArea[];

int findByName(char* name, Student students[], int num, Student result[]){
	int i;
	int resultNum = 0;
	for (i = 0; i < num; i++){
		if (strcmp(name, students[i].name) == 0){
			result[resultNum] = students[i];
		}
	}
	return resultNum;
}

Student findById(int id, Student students[], int num){
	int i;
	for (i = 0; i < num; i++){
		if (students[i].id == id){
			return students[i];
		}
	}
	return NULL;
}

void findAndUpdate(){
	print("---------------------");
	print("查询与修改功能");
	print("当前范围：");
	print(currentArea);
	printSortOption();
	int choice = getChoice(0, 2);
	if (choice == 0){
		return;
	}
	switch (choice){
		case 1:
			break;
		case 2:
			break;
	}
}
 
