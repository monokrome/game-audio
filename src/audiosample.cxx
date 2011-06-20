#include "audiosample.hpp"

using namespace GameAudio;

IAudioSample::IAudioSample(bool streaming)
{
	isInitialized = false;
}

IAudioSample::~IAudioSample()
{
}

void IAudioSample::Initialize()
{
	isInitialized = true;
}

void IAudioSample::ShutDown()
{
}

bool IAudioSample::IsInitialized()
{
	return isInitialized;
}

bool IAudioSample::IsStreaming()
{
	return isStreaming;
}
