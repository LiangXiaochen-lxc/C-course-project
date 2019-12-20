#include "struct.h"
#include <string.h> 
#include <stdio.h>

extern Area area[];
extern char currentArea[];
extern int areaNum;
extern Student student[];
extern Student nowStudent[];
extern int nowStudentNum;
extern int studentNum;

void changeArea(){
	int i, j;
    print("当前范围：");
    print(currentArea);
    print("选择新范围的编号");
    printArea(area, areaNum);
    int choice;
	do {
    	scanf("%d", &choice);
    	if (choice >= 0 && choice <= areaNum){
    		break;
		} else {
			print("范围错误");
		}
	} while (1);
    if (choice == 0){
        strcpy(currentArea, "全体");
        for (i = 0; i < studentNum; i++){
			nowStudent[i] = student[i];
		}
		nowStudentNum = studentNum;
    } else {
        strcpy(currentArea, area[choice-1].name);
        for (i = 0, j = 0; i < studentNum; i++){
    		if (student[i].aid == choice){
    			nowStudent[j] = student[i];
    			j++;
			}
		}
		nowStudentNum = j;
    }
    print("范围已修改为：");
    print(currentArea);
}
