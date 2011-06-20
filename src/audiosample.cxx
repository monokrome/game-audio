#include "audiosample.hpp"

using namespace GameAudio;

IAudioSample::IAudioSample(bool streaming)
{
}

IAudioSample::~IAudioSample()
{
}

bool IAudioSample::IsStreaming()
{
	return isStreaming;
}
