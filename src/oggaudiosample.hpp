#ifndef OGGAUDISAMPLE_HPP
#define OGGAUDISAMPLE_HPP

#include <string>
#include <ogg/ogg.h>
#include <vorbis/vorbisfile.h>

#include "audiosample.hpp"

namespace GameAudio
{

	class OggAudioSample : public IAudioSample
	{
	public:
		virtual void Open(std::string filename);
		virtual void Close();

		virtual void *GetData();

	private:
		OggVorbis_File oggData;

		vorbis_info* vorbisInfo;
		vorbis_comment* vorbisComment;
	};

}

#endif
