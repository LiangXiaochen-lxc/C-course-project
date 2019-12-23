#include "struct.h"
#include <stdio.h>
#include <string.h>
//ȫ�ֱ��� 
extern char currentArea[];
extern Student* nowStudent[];
extern int nowStudentNum;

/*
������
��������Ѱ��ѧ��

name ҪѰ�ҵ�ѧ������
students ����Щѧ����Ѱ��
num students�а�����ѧ������
result ����ҵ���ѧ����Ϣ
 
return �ҵ���ѧ������ 
*/
int findByName(char* name, Student* students[], int num, Student* result[]){
	int i;
	int resultNum = 0;//�ҵ���ѧ���� 
	for (i = 0; i < num; i++){
		if (strcmp(name, students[i]->name) == 0){//�����ѧ����������Ŀ����ͬ 
			result[resultNum] = students[i];//���ҵ���ѧ���浽result 
			resultNum++;//�ҵ���ѧ������1 
		}
	}
	return resultNum;//�����ҵ������� 
}

/*
��Ц��
����ѧ��Ѱ��ѧ��

id ҪѰ�ҵ�ѧ��
students ����Щѧ����Ѱ��
num students�а�����ѧ����

return ָ��Ŀ��ѧ���ṹ���ָ�� 
*/
Student* findById(int id, Student* students[], int num){
	int i;
	for (i = 0; i < num; i++){
		if (students[i]->id == id){//�����ѧ����ѧ�ź�Ŀ����ͬ 
			return students[i];//���ظ�ѧ����ָ�� 
		}
	}
	Student no;
	no.id = -1; 
	Student* null = &no;
	return null;//û��Ŀ���򷵻�һ��idΪ-1��ѧ�� 
}

/*
��Ц�� 
Ѱ��ѧ�����Ҹ��µ����� 
*/ 
void findAndUpdate(){
	print("---------------------");
	print("��ѯ���޸�");
	print("��ǰ��Χ��");
	print(currentArea);
	printFindOption();
	int choice = getChoice(0, 2);
	if (choice == 0){
		return;
	}
	Student* result[5000];
	switch (choice){
		case 1:
			print("����Ŀ��ѧ����ѧ�ţ�");
			int id;
			scanf("%d", &id);
			result[0] = findById(id, nowStudent, nowStudentNum);
			if (result[0]->id == -1){
				printf("û��ѧ��Ϊ%d��ѧ��\n", id);
				break;
			} else {
				printStudent(result, 1);
				print("�Ƿ���Ҫ�޸ĸ�ѧ����Ϣ��");
				print("�ǣ�����1 ���ǣ�����0");
				int updateChoice = getChoice(0, 1);
				if (updateChoice){
					print("�޸ĵڼ��Ƶĳɼ���");
					int subjectChoice;
					do {
						scanf("%d", &subjectChoice);
						if (subjectChoice >= 1 && subjectChoice <= 10){
							break;
						}
					} while (1);
					print("�����³ɼ�");
					double newScore;
					do {
						scanf("%lf", &newScore);
						if (newScore >= 0 && newScore <= 100){
							break;
						}
					} while (1);
					double change = newScore - result[0]->score[subjectChoice-1];
					change /= 10;
					result[0]->score[10] += change;
					result[0]->score[subjectChoice-1] = newScore;
					print("���޸�");
					printStudent(result, 1);
				}
			}
			break;
		case 2:
			print("����Ŀ��ѧ����������");
			char name[100];
			scanf("%s", name);
			int count = findByName(name, nowStudent, nowStudentNum, result);
			if (count == 0){
				printf("û������Ϊ%s��ѧ��\n", name);
				break;
			} else {
				printStudent(result, count);
				print("�Ƿ���Ҫ�޸�ѧ����Ϣ��");
				print("�ǣ�����1 ���ǣ�����0");
				int updateChoice = getChoice(0, 1);
				if (updateChoice){
					print("�޸ĵڼ���ѧ���ĳɼ���");
					int countChoice;
					do {
						scanf("%d", &countChoice);
						if (countChoice >= 1 && countChoice <= count){
							break;
						}
					} while (1);
					print("�޸ĵڼ��Ƶĳɼ���");
					int subjectChoice;
					do {
						scanf("%d", &subjectChoice);
						if (subjectChoice >= 1 && subjectChoice <= 10){
							break;
						}
					} while (1);
					print("�����³ɼ�");
					double newScore;
					do {
						scanf("%lf", &newScore);
						if (newScore >= 0 && newScore <= 100){
							break;
						}
					} while (1);
					double change = newScore - result[countChoice-1]->score[subjectChoice-1];
					change /= 10;
					result[countChoice-1]->score[10] += change;
					result[countChoice-1]->score[subjectChoice-1] = newScore;
					print("���޸�");
					printStudent(result, count);
				}
			}
			break;
	}
}
 
