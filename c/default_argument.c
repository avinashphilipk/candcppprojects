#include <stdio.h>
void find(int arg = 0)
{
	printf("arg %d\n",arg);
}
int main()
{
	find(3);
	find();
	return 0;
}
