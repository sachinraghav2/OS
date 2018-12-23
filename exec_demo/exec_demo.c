#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Before exec: \n");
	execl("/bin/ls", "/bin/ls", "-a", "-l", NULL);
	printf("after exec: \n");
	return 0;
}
