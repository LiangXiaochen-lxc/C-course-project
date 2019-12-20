#include <stdio.h>
int getChoice(int min, int max){
	char input[2];
	do{
		gets(input);
	}while(input[0] < min+'0' || input[0] > max+'0' || input[1] != '\0');
	return input[0] - '0';
}
void print(char* target){
	printf("%s\n", target);
}
