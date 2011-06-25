#include <stdexcept>
#include "audiosample.hpp"
#include <string.h>

using namespace GameAudio;

IAudioSample::IAudioSample(bool streaming)
{
	isInitialized = false;
	isStreaming = streaming;
}

IAudioSample::~IAudioSample()
{
}

void IAudioSample::Initialize()
{
	char *data;
	ALenum error;

	if (isStreaming)
	{
		alGenBuffers(streamingBufferCount, buffer);
		error = alGetError();

		if (error != AL_NO_ERROR)
		{
			throw std::runtime_error("Couldn't generate streaming buffers.");
		}
	}
	else
	{
		data = (char*) GetData();

		// TODO: Use the cache to make sure we don't load this unnecessarily.
		alBufferData(buffer[0], GetFormat(), data,
			sizeof(char) * strlen(data), info.sample_rate);

		error = alGetError();

		if (error != AL_NO_ERROR)
		{
			throw std::runtime_error("Couldn't buffer data.");
		}
	}

	isInitialized = true;
}

void IAudioSample::ShutDown()
{
}

ALenum IAudioSample::GetFormat()
{
	if (info.channels == 1)
	{
		return AL_FORMAT_MONO16;
	}

	return AL_FORMAT_STEREO16;
}

bool IAudioSample::IsInitialized()
{
	return isInitialized;
}

bool IAudioSample::IsStreaming()
{
	return isStreaming;
}
