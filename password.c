#include <string.h>
#include <stdio.h>
/*
��Ц��
��¼

return �ɹ�����1 ʧ�ܷ���0 
*/ 
int login(){
    unsigned char input[100];
    unsigned char password[100] = "pikachu";
    FILE* target = fopen("password", "r");
    if (target != NULL){
        fgets(password, 100, (FILE*) target);
        decode(password); 
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
