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
    print("��ǰ��Χ��");
    print(currentArea);
    print("ѡ���·�Χ�ı��");
    printArea(area, areaNum);
    int choice;
	do {
    	scanf("%d", &choice);
    	if (choice >= 0 && choice <= areaNum){
    		break;
		} else {
			print("��Χ����");
		}
	} while (1);
    if (choice == 0){
        strcpy(currentArea, "ȫ��");
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
    print("��Χ���޸�Ϊ��");
    print(currentArea);
}
