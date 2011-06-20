#ifndef AUDIOSAMPLE_HPP
#define	AUDIOSAMPLE_HPP

#include <string>
#include <map>

#include "common.hpp"

using namespace std;

const int streamingBufferCount = 4;
const int streamingBufferSize = 65536;
const int readBufferSize = 4096;

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

		void Initialize();
		void ShutDown();

		bool IsInitialized();
		ALenum GetFormat();

		virtual void Open(std::string filename) = 0;
		virtual void Close() = 0;
		virtual void* GetData();

		bool IsStreaming();

	protected:
		sample_info_t info;
		std::map<std::string, std::string> metadata;

	private:
		ALuint buffer[streamingBufferCount];

		bool isStreaming;
		bool isInitialized;
	};

}

#endif
