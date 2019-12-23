#include <stdio.h>
#include <string.h>
/*
梁笑尘
重置密码流程 
*/ 
void resetPassword(){
	if (login()){
		unsigned char password[1000];
		unsigned char temp[1000];
		print("输入新密码");
		scanf("%s", password);
		print("确认新密码");
		scanf("%s", temp);
		if (strcmp(password, temp) == 0){
			FILE *target = fopen("password", "w");
			encode(password);
			fputs(password, target);
			fclose(target);
			print("密码已修改");
		} else {
			print("两次输入的密码不一致");
		}
	}
}
