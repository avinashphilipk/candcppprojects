#include <stdio.h>
#include <string.h>
char *foo(void)
{
	static char chptr[100];
	strcpy(chptr,"Hai");
	return chptr;
}
int main()
{
	printf("%s\n",foo());
	return 0;
}