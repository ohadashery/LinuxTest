
#include <stdio.h>
#include "mytestthread.h"

void * my_thread(void *arg)
{
        int count=0;

        while (1)
        {
                printf ("my_thread: %d\n", count++);
                sleep(1);
        }

        return NULL;
}

