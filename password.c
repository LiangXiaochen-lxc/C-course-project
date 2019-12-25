#include <string.h>
#include <stdio.h>
/*
梁笑尘
登录

return 成功返回1 失败返回0 
*/ 
int login(){
    unsigned char input[100];
    unsigned char password[100] = "F54bg3%&*[6j5!]456";
    FILE* target = fopen("password", "r");
    if (target != NULL){
        fgets(password, 100, (FILE*) target);
        decode(password); 
        printf("请输入密码\n");
    } else {
        printf("请输入初始密码\n");
    }
    gets(input);
    fclose(target);
    if (strcmp(input, password) == 0){
        printf("通过验证\n");
        return 1;
    } else {
        printf("密码错误\n");
        return 0;
    }
}
