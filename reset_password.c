#include <stdio.h>
#include <string.h>
/*
��Ц��
������������ 
*/ 
void resetPassword(){
	if (login()){
		unsigned char password[1000];
		unsigned char temp[1000];
		print("����������");
		scanf("%s", password);
		print("ȷ��������");
		scanf("%s", temp);
		if (strcmp(password, temp) == 0){
			FILE *target = fopen("password", "w");
			encode(password);
			fputs(password, target);
			fclose(target);
			print("�������޸�");
		} else {
			print("������������벻һ��");
		}
	}
}
