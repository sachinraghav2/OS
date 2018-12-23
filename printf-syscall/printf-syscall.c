#include<stdio.h>
#include <unistd.h>
int main()
{
	char buff[25];
	int count;
	count=read(0, buff, 20);
	write(1,buff, count);
	return 0;
}
