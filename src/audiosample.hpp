#ifndef AUDIOSAMPLE_HPP
#define	AUDIOSAMPLE_HPP

#include <string>

#include "common.hpp"

using namespace std;

namespace GameAudio
{

	typedef struct {
		unsigned short channels; // Number of channels contained in this data
		unsigned short bit_depth; // The bit-depth for each frame of audio
		unsigned int sample_rate; // The number of samples that occur per second
	} sample_info_t;

	class IAudioSample
	{
	public:
		IAudioSample(bool streaming = false);
		~IAudioSample();

		bool IsStreaming();

	protected:
		sample_info_t info;

	private:
		bool isStreaming;
	};

}

#endif
