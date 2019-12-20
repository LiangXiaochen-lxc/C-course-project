#include <string.h>
#include <stdio.h>

int login(){
    char input[100];
    char password[100] = "";
    FILE* target = fopen("password", "r");
    if (target != NULL){
        fgets(password, 100, (FILE*) target);
        printf("请输入密码\n");
    } else {
        printf("请输入初始密码\n");
    }
    fclose(target);
    gets(input);
    if (strcmp(input, password) == 0){
        printf("通过验证\n");
        return 1;
    } else {
        printf("密码错误\n");
        return 0;
    }
}
