#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "mytestthread.h"
#include "mytestlib.h"

int main(int argc, char **argv)
{
	pthread_t tid=0;

	printf ("starting test...argc=%d, argv[1]=%s\n", argc, argv[1]);
	
	int rc=pthread_create( &tid, NULL, &my_thread, NULL );
	
	printf ("Created thread 'my_thread', rc=%d\n", rc);

	rc=pthread_create(&tid, NULL, &mytestlibfunc, NULL );

	printf ("Created thread 'mytestlibfunc', rc=%d\n", rc);

	if ( argc == 1 || *argv[1]=='0' )
	{
		goto __wait;
	}

	printf ("creating another instance of mytest....\n" );

	pid_t process = fork();
	if ( process < 0 )
	{
		perror("fork");
		printf ("fork failed, rc=%d\n", process );
	}
	else if (process == 0 )
	{
		execl("./mytest","./mytest","0", NULL );
	}

__wait:
	while(1)
	{
		sleep(1);
	}

	return 0;
}

