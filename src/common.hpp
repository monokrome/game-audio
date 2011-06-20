/**
 * Every OS thinks OpenAL should install it's headers differently, so we use
 * this to include them properly.
 */
#ifndef WIN32
	#include <AL/al.h>
#else
	#include <al.h>
#endif
