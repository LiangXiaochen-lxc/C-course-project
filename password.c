#include <string.h>
#include <stdio.h>

int login(){
    char input[100];
    char password[100] = "";
    FILE* target = fopen("password", "r");
    if (target != NULL){
        fgets(password, 100, (FILE*) target);
        printf("����������\n");
    } else {
        printf("�������ʼ����\n");
    }
    fclose(target);
    gets(input);
    if (strcmp(input, password) == 0){
        printf("ͨ����֤\n");
        return 1;
    } else {
        printf("�������\n");
        return 0;
    }
}
