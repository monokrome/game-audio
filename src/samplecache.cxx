#include "samplecache.hpp"

ISampleCache::ISampleCache()
{
}

ISampleCache::~ISampleCache()
{
}

/**
 * Creates a new sample cache item with the given identifier, updates it with
 * the sample data from raw_data, and sets it up to match the given piece data.
 *
 * @param identifier
 * @param raw_data
 * @param info
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
