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

		bool IsInitialized();
		bool EffectsAvailable();

	private:
		bool isInitialized;
		bool effectsAvailable;

		ALCcontext *context;
		ALCdevice *playbackDevice;

		ALCint auxilarySendCount;
	};

}

#endif
