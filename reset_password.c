#include <stdio.h>
#include <string.h>
void resetPassword(){
	if (login()){
		char password[1000];
		char temp[1000];
		print("输入新密码");
		scanf("%s", password);
		print("确认新密码");
		scanf("%s", temp);
		if (strcmp(password, temp) == 0){
			FILE *target = fopen("password", "w");
			fputs(password, target);
			fclose(target);
			print("密码已修改");
		} else {
			print("两次输入的密码不一致");
		}
	}
}
