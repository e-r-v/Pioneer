#include "mytimer.h"


static struct timespec start, end;


void initializeTimer()
{
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
}


void delayTimer(long timeout)
{
	long t_ns = 0;
	do
	{		
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
		
		t_ns = (long)(end.tv_sec - start.tv_sec) * 1000000000 +
              (long)(end.tv_nsec - start.tv_nsec);
	}while (t_ns < timeout);
	
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
}
