#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int i;
	printf("------Before Calling!-------");
	sleep(5);
	i=system("./proj2");
    printf("------After Calling!--------");
	printf("return value =%d\n");
	return 0;

}
