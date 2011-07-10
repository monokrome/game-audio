/**
 * Every OS thinks OpenAL should install it's headers differently, and
 * Apple computers do effects in a completely different way. They don't
 * use EFX - so, we use this to include them properly.
 */
#if defined(_WIN32)
	#include <al.h>
	#include <alc.h>

	#ifndef __APPLE__
		#include <efx.h>
	#endif

#else
	#include <AL/al.h>
	#include <AL/alc.h>
	#include <AL/efx.h>

#endif
