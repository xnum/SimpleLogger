#include <stdio.h>

#ifndef DEBUG_CTRL_H
#define DEBUG_CTRL_H
#define DEBUG_CTRL_CONTINUE

	#define DEBUG 1
	#define INFO  2
	#define WARN  3
	#define ERROR 4
	#define NONE  7

#endif

#ifdef AUTHER_x000032001

	extern int xxxDebugLevel __attribute__((unused));

#else

	#define AUTHER_x000032001
	static int xxxDebugLevel __attribute__((unused)) = DEBUG;

#endif

#ifdef DEBUG_CTRL_CONTINUE

	#define SET_DEBUG_LEVEL(x) (xxxDebugLevel=(x))

	#define dprintf(inputLV,format,...)			\
			do { if((inputLV)>=xxxDebugLevel) {		\
			fprintf(stderr,"%10s:%3d %s() # " format,__FILE__,__LINE__,__func__,##__VA_ARGS__);	\
			} } while(0)

#endif