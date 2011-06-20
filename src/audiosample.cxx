#include "audiosample.hpp"

using namespace GameAudio;

IAudioSample::IAudioSample(bool streaming)
{
}

IAudioSample::~IAudioSample()
{
}

void IAudioSample::Initialize()
{
}

void IAudioSample::ShutDown()
{
}

bool IAudioSample::IsStreaming()
{
	return isStreaming;
}
