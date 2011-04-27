#include <stdexcept>
#include "samplecache.hpp"

using namespace gameaudio;

/**
 * Creates (or recreates) a sample cache entry.
 *
 * Creates a new sample cache entry with the given identifier, updates it with
 * the sample data from raw_data, and sets it up to match the given piece of
 * data.
 *
 * @param identifier A string that is used to uniquely identify the audio data
 * @param info A sample_info_t* structure that describes this audio's format
 * @param raw_data The data that we want affiliated with the given identifier
 */
void ISampleCache::create(const string identifier,
                          sample_info_t* info,
                          const string raw_data)
{
	// If this identifier already exists, we need reset it to initial values.
	clear(identifier);

	set_info(identifier, info);
	update(identifier, raw_data);
}

/**
 * Raises an error due to a bad identifier being passed.
 *
 * @param identifier The identifier that wasn't found in our cache.
 */
void ISampleCache::throw_bad_identifier(string identifier)
{
	throw std::runtime_error("Identifier " + identifier + " not in cache.");
}

ISampleCache::ISampleCache()
{
}

ISampleCache::~ISampleCache()
{
}
