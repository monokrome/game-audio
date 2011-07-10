/**
 * Every OS thinks OpenAL should install it's headers differently, and
 * Apple computers do effects in a completely different way. They don't
 * use EFX - so, we use this to include them properly.
 */
#if defined(__linux__)
	#include <AL/al.h>
	#include <AL/alc.h>
	#include <AL/efx.h>

#elif defined(_WIN32)
	#include <al.h>
	#include <alc.h>
	#include <efx.h>

#elif defined(__APPLE__)
	#include <al.h>
	#include <alc.h>

#else
	#error A supported platform was not detected. Can not build.

#endif
