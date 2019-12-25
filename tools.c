#include <stdio.h>
#include <string.h>
#include "struct.h"

extern char currentArea[];
extern Area area[];
extern Sex sex[];

/*
��Ц��
��ȡ�û������һ��min��max֮����� 
*/ 
int getChoice(int min, int max){
    int input;
    do{
        scanf("%d", &input);
        fflush(stdin);
    }while(input < min || input > max);
    return input;
}

/*
��Ц��
���һ���ַ��������� 
*/ 
void print(char* target){
    printf("%s\n", target);//
}

/*
��Ц�� 
��ӭ���� 
*/ 
void welcome(){
    print("---------------------");
    print("ѧ���ɼ�����ϵͳ");
    print("��Ц�� �ƻ�ӳ ������ ������");
}

/*
��Ц�� 
���˵� 
*/ 
void printMenu(){
    print("---------------------");
    print("������");
    print("��ǰ��Χ��");
    print(currentArea);
    print("1 ������Χ");
    print("2 �������");
    print("3 ���ҡ��޸�");
    print("4 �����޸�");
    print("0 �˳�");
}

/*
��Ц�� 
����ѡ�� 
*/ 
void printSortOption(){
	print("1 ������������");
	print("2 ���ݵ��Ƴɼ�����");
	print("3 ����ƽ���ɼ�����");
	print("0 ������һ��");
}

/*
��Ц�� 
Ѱ��ѡ�� 
*/ 
void printFindOption(){
	print("1 ����ѧ�Ų���");
	print("2 ������������");
	print("0 ������һ��"); 
}

/*
��Ц�� 
�����Χ 
*/ 
void printArea(Area area[], int areaNum){
	int i; 
	print("0 ȫ��");//
    for (i = 0; i < areaNum; ++i) {//
        printf("%d %s\n", i+1, area[i].name);
    }
}

/*
��Ц�� 
���ѧ����Ϣ 
*/ 
void printStudent(Student* nowStudent[], int studentNum){
	int i, j;
	print("____________________________________________________________________________________________________________"); 
	printf("|  ѧ��|  ����|�Ա�|      ѧԺ|��һ��|�ڶ���|������|���Ŀ�|�����|������|���߿�|�ڰ˿�|�ھſ�|��ʮ��|ƽ����|\n"); 
	for (i = 0; i < studentNum; i++){
		printf("|%6d|%6s|%4s|%10s", nowStudent[i]->id,//
               nowStudent[i]->name, sex[nowStudent[i]->sid].name, area[nowStudent[i]->aid-1].name);
        for (j = 0; j < 11; j++){
            printf("|%6.2lf", nowStudent[i]->score[j]);//
        }
        printf("|\n");
	}
}

/*
��Ц��
���� 
*/
void encode(unsigned char* password){
	unsigned char encoded[100];
	int i, j;
	for (i = strlen(password)-1, j = 0; i >= 0; i--, j++){
		encoded[j] = password[i]+88;
	}
	strcpy(password, encoded);
}

/*
��Ц��
���� 
*/ 
void decode(char* password){
	unsigned char decoded[100];
	int i, j;
	for (i = strlen(password)-1, j = 0; i >= 0; i--, j++){
		decoded[j] = password[i]-88;
	}
	strcpy(password, decoded);
}
