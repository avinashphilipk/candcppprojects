#include <stdio.h>
int main(){
	char *ptr	= "abcdef";
	system("cls");
	printf("%c\n",*ptr++);
	printf("%c\n",*++ptr);
	//printf("%c\n",++*ptr);
	printf("%c\n",*ptr);
	return 0;
}