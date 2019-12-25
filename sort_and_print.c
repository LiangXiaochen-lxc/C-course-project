#include "struct.h"
#include <string.h>
#include <stdio.h>
#define PAGE_SIZE 15

extern char currentArea[];
extern Student* nowStudent[];
extern int nowStudentNum;

/*
������
������������

students ����Щѧ����Ѱ��
mode 1�������� 0��������
num students�е�ѧ������ 
*/ 
void sortByName(Student* students[], int mode, int num){
	int i, j;
	Student* t;
	if (mode == 1) {//�������� 
		for (i = 0; i < num-1; i++) {//�������� 
			for(j = i+1; j < num; j++) {
				if(strcmp(students[i]->name, students[j]->name) > 0) {
					t = students[i];
					students[i] = students[j];
					students[j] = t;
				}
			}
		}
	} else {//�������� 
		for (i = 0; i < num-1; i++){//�������� 
			for(j = i+1; j<num; j++){
				if(strcmp(students[i]->name, students[j]->name) < 0){
					t = students[i];
					students[i] = students[j];
					students[j] = t;
				}
			}
		}
	}
}
 
/*
������
������������

subject ���ڼ���ѧ������ ��11��Ϊƽ��ֵ 
students ����Щѧ����Ѱ��
mode 1�������� 0��������
num students�е�ѧ������ 
*/ 
void sortByScore(int subject, Student* students[], int mode, int num){
	int i, j;
	Student* t;
	if (mode == 1) {//�������� 
		for (i = 0; i < num-1; i++){//�������� 
			for(j = i+1; j < num; j++){
				if(students[i]->score[subject] > students[j]->score[subject]){
					t = students[i];
					students[i] = students[j];
					students[j] = t;
				}
			}
		}
	} else {//��������
		for (i = 0; i < num-1; i++){//�������� 
			for(j = i+1; j < num; j++){
				if(students[i]->score[subject] < students[j]->score[subject]){
					t = students[i];
					students[i] = students[j];
					students[j] = t;
				}
			}
		}
	}
}

/*
��Ц�� 
����������� 
*/ 
void sortAndPrint(){
	print("---------------------");
	print("�������������");
	print("��ǰ��Χ��");
	print(currentArea);
	printSortOption();
	int choice = getChoice(0, 3);
	if (choice == 0){
		return;
	}
	print("������������1 ������������0");
	int sortChoice = getChoice(0, 1);
	switch (choice){
		case 1:
			sortByName(nowStudent, sortChoice, nowStudentNum);
			break;
		case 2:
			print("���ݵڼ��Ƶĳɼ�����");
			int socreChoice = getChoice(1, 10);
			socreChoice--;
			sortByScore(socreChoice, nowStudent, sortChoice, nowStudentNum);
			break;
		case 3:
			sortByScore(10, nowStudent, sortChoice, nowStudentNum);
			break;
	}
	int maxPage = nowStudentNum / PAGE_SIZE;
	if (nowStudentNum % PAGE_SIZE != 0){
		maxPage++;
	}
	int currentPage = 1; 
	do {
		printStudent(nowStudent + (currentPage-1)*PAGE_SIZE, 
			currentPage==maxPage ? nowStudentNum%PAGE_SIZE : PAGE_SIZE);
		printf("��%dҳ ��%dҳ\n", currentPage, maxPage);
		print("������Ҫǰ����ҳ�� ����0������һ��");
	} while (currentPage = getChoice(0, maxPage));
}

