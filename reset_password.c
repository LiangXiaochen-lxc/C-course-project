#include <stdio.h>
#include <string.h>
void resetPassword(){
	if (login()){
		char password[1000];
		char temp[1000];
		print("����������");
		scanf("%s", password);
		print("ȷ��������");
		scanf("%s", temp);
		if (strcmp(password, temp) == 0){
			FILE *target = fopen("password", "w");
			fputs(password, target);
			fclose(target);
			print("�������޸�");
		} else {
			print("������������벻һ��");
		}
	}
}
