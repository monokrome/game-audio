#include <stdexcept>
#include "oggaudiosample.hpp"

using namespace GameAudio;

int vorbis_close_func(void *datasource);
size_t vorbis_read_func(void *ptr, size_t size, size_t nmemb, void *datasource);
int vorbis_seek_func(void *datasource, ogg_int64_t offset, int whence);
long vorbis_tell_func(void *datasource);

void OggAudioSample::Open(std::string filename)
{
	ov_callbacks oggCallbacks;

	oggCallbacks.close_func = vorbis_close_func;
	oggCallbacks.read_func = vorbis_read_func;
	oggCallbacks.seek_func = vorbis_seek_func;
	oggCallbacks.tell_func = vorbis_tell_func;

	FILE *oggFile = fopen(filename.c_str(), "rb");

	if (!oggFile)
	{
		throw std::runtime_error("Could not open file for ogg decoding.");
	}

	if (ov_open_callbacks(oggFile, &oggData, NULL, 0, oggCallbacks) < 0)
	{
		throw std::runtime_error("Could not properly open ogg stream.");
	}

	vorbisInfo = ov_info(&oggData, -1);
	vorbisComment = ov_comment(&oggData, -1);

	info.channels = vorbisInfo->channels;
	info.bit_depth = vorbisInfo->bitrate_nominal;
	info.sample_rate = vorbisInfo->rate;

	Initialize();
}

void OggAudioSample::Close()
{
	ShutDown();

	ov_clear(&oggData);
}

/**
 * Returns a void pointer this sample's entire PCM data.
 */
void* OggAudioSample::GetData()
{
	char buffer_data[readBufferSize];
	int *bitstream = NULL;
	std::string result;

	// TODO: Add support for 8-bit samples.
	while (ov_read(&oggData, buffer_data, readBufferSize, 0, 2, 1, bitstream) > 0)
	{
		result += buffer_data;
	}

	return const_cast<char *>(result.c_str());
}

/**
 * Callback functions used by Ogg file open, read, seek, and close operations.
 */
int vorbis_close_func(void *datasource)
{
	fclose((FILE*) datasource);

	return 0; // Why did Xiph make this return int? :(
}

size_t vorbis_read_func(void *ptr, size_t size, size_t nmemb, void *datasource)
{
	return fread(ptr, size, nmemb, (FILE*) datasource);
}

int vorbis_seek_func(void *datasource, ogg_int64_t offset, int whence)
{
	return fseek((FILE*) datasource, (long) offset, whence);
}

long vorbis_tell_func(void *datasource)
{
	return ftell((FILE*) datasource);
}
