#ifndef GAMEAUDIO_HPP
#define GAMEAUDIO_HPP

#include "common.hpp"

namespace GameAudio
{

	class Audio
	{
	public:
		Audio();
		~Audio();

		void Initialize();
		void ShutDown();

	private:
		ALuint context;
	};

}

#endif
