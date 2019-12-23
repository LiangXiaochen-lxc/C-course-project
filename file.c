#include <stdio.h>
#include <string.h>
#include "struct.h"
//ȫ�ֱ��� 
extern int studentNum;
extern int areaNum; 

/*
�ƻ�ӳ
���ļ���ȡ��Χ��Ϣ

fileName �ļ���
area �ļ������ݱ��浽����

return 1�ɹ� 0�Ҳ����ļ� 
*/ 
int readC(char* fileName, Area area[]){
    int i;
    FILE* target = fopen(fileName, "r");//��rģʽ���ļ� 
    if (target == NULL){//�Ҳ�����ΪfileName���ļ� ����0 
        return 0;
    }
    fscanf(target, "%d", &areaNum);//��ȡ��Χ���� 
    for (i = 0; i < areaNum; i++){//��ȡ��Χid�ͷ�Χ�� 
        fscanf(target, "%d %s", &area[i].id, area[i].name);
    }
    fclose(target);//�ر��ļ� 
    return 1;
}

/*
�ƻ�ӳ
���ļ���ȡ�Ա���Ϣ

fileName �ļ���
sex �ļ������ݱ��浽����

return 1�ɹ� 0�Ҳ����ļ� 
*/ 
int readS(char* fileName, Sex sex[]){
    int i, num;
    FILE* target = fopen(fileName, "r");//��rģʽ���ļ� 
    if (target == NULL){//�Ҳ�����ΪfileName���ļ� ����0 
        return 0;
    }
    fscanf(target, "%d", &num);//���Ա����� 
    for (i = 0; i < num; i++){//���Ա�id���Ա��� 
        fscanf(target, "%d%s", &sex[i].id, sex[i].name);
    }
    fclose(target);//�ر��ļ� 
    return 1;
}

/*
�ƻ�ӳ
���ļ���ȡѧ����Ϣ

fileName �ļ���
student �ļ������ݱ��浽����

return 1�ɹ� 0�Ҳ����ļ� 
*/ 
int readStu(char* fileName, Student student[]){
    int i, j;
    FILE* target = fopen(fileName, "r");//��rģʽ���ļ� 
    if (target == NULL){//�Ҳ�����ΪfileName���ļ� ����0 
        return 0;
    }
    fscanf(target, "%d", &studentNum);//��ȡѧ������ 
    for (i = 0; i < studentNum; i++){//��ѧ����Ϣ 
        fscanf(target, "%d %s %d %d", &student[i].id,//�� ѧ�� ���� �Ա���� ѧԺ���� 
               student[i].name, &student[i].sid, &student[i].aid);
        for (j = 0; j < 10; j++){//��10�Ƴɼ� 
            fscanf(target, " %lf", &student[i].score[j]);
        }
    }
    fclose(target);//�ر��ļ� 
    return 1;
}

/*
��Ц��
��ѧ����Ϣд���ļ�

fileName Ŀ���ļ���
student Ҫд���ļ���ѧ����Ϣ
studentNum Ҫд���ļ���ѧ������ 
*/ 
void writeStu(char* fileName, Student student[], int studentNum){
	int i, j;
	FILE* target = fopen(fileName, "w");//��wģʽ���ļ� 
	fprintf(target, "%d\n", studentNum);//дѧ������ 
	for (i = 0; i < studentNum; i++){//дѧ����Ϣ 
        fprintf(target, "%d %s %d %d", student[i].id,//д ѧ�� ���� �Ա���� ��Χ���� 
               student[i].name, student[i].sid, student[i].aid);
        for (j = 0; j < 10; j++){//д10�εĳɼ� 
            fprintf(target, " %.2lf", student[i].score[j]);
        }
        fprintf(target, "\n");
    }
    fclose(target);//�ر��ļ� 
}
