
#include <stdio.h>

void * mytestlibfunc(void *arg)
{
	int t=0;

	while ( 1 )
	{
		printf("mytestlibfunc: %d\n", t++);
		sleep(1);
	}


	return 0;
}
