#include <stdexcept>
#include "audio.hpp"

using namespace GameAudio;

Audio::Audio()
{
	context = NULL;
	playbackDevice = NULL;

	effectsAvailable = false;
	isInitialized = false;
}

Audio::~Audio()
{
	ShutDown();
}

void Audio::Initialize()
{
	const unsigned int idealAuxilarySendCount = 4;
	ALint options[4];

	// Request a specific number of auxilary sends per buffer.
	options[0] = ALC_MAX_AUXILIARY_SENDS;
	options[1] = idealAuxilarySendCount;

	playbackDevice = alcOpenDevice(NULL);

	if (playbackDevice != NULL)
	{
		throw std::runtime_error("Couldn't open playback device.");
	}

	context = alcCreateContext(playbackDevice, options);

	if (context == NULL)
	{
		throw std::runtime_error("Couldn't create playback device context.");
	}

	if (effectsAvailable)
	{
		alcGetIntegerv(playbackDevice, ALC_MAX_AUXILIARY_SENDS,
		               sizeof(auxilarySendCount), &auxilarySendCount);
	}

	#ifdef GAMEAUDIO_SPEED_OF_SOUND
		SetSpeedOfSound(GAMEAUDIO_SPEED_OF_SOUND);
	#endif

	isInitialized = true;
}

void Audio::ShutDown()
{
	if (playbackDevice != NULL)
	{
		if (context != NULL)
		{
			if (alcGetCurrentContext() == context)
			{
				alcMakeContextCurrent(NULL);
			}

			alcDestroyContext(context);
		}

		alcCloseDevice(playbackDevice);
		playbackDevice = NULL;
	}

	context = NULL;

	effectsAvailable = false;
	isInitialized = false;
}

void Audio::MakeCurrent()
{
	alcMakeContextCurrent(context);

	if (alGetError() != AL_NO_ERROR)
	{
		throw std::runtime_error("Unabled to make audio context current.");
	}
}

/**
 * Functions which expose the state of our audio system to developers.
 */
bool Audio::EffectsAvailable()
{
	return alcIsExtensionPresent(playbackDevice, "ALC_EXT_EFX");
}

/**
 * Functions which modify the speed of sound and number of units per meter, so
 * that developers are able to adjust the movement of audio to better fit
 * their game world.
 */
void SetSpeedOfSound(const float newSpeedOfSound)
{
	alSpeedOfSound(newSpeedOfSound);

	if (alGetError() != AL_NO_ERROR)
	{
		throw std::runtime_error("Could not configure the speed of sound.");
	}
}

void SetMetersPerUnit(const float newMetersPerUnit)
{
	alListenerf(AL_METERS_PER_UNIT, newMetersPerUnit);
}
