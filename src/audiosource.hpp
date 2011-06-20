#ifndef AUDIOSOURCE_HPP
#define AUDIOSOURCE_HPP

#include "audiosample.hpp"

namespace GameAudio
{

	/**
	 * Represents a single entity that can emit a sound in our game world.
	 */
	class CAudioSource
	{
	public:
		CAudioSource();
		~CAudioSource();

		void Play();
		void Pause();
		void Stop();

	protected:
		IAudioSample* sample;

	private:
		bool isPlaying;
		bool isPaused;

		ALuint source;
	};

}

#endif
