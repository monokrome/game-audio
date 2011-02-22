/* 
 * File:   simplesamplecache.cxx
 * Author: Brandon "monokrome" Stoner
 *
 * Created on February 21, 2011, 6:40 AM
 */

#include <string>
#include "simplesamplecache.hpp"

using namespace std;

/**
 * Completely flushes all data from the cache.
 */
void SimpleSampleCache::flush()
{
	map<string, cache_data_t*>::iterator iter;
	
	for (iter = cache_data.begin(); iter != cache_data.end(); ++iter)
		clean_data(iter);

	cache_data.clear();
}

/**
 * Completely clears the given identifier from the cache.
 *
 * @param identifier
 */
void SimpleSampleCache::clear(const string identifier)
{
	map<string, cache_data_t*>::iterator iter = cache_data.find(identifier);

	if (iter != cache_data.end())
	{
		clean_data(iter);

		cache_data.erase(iter); // Finally, erase this item from the cache data
	}
}

/**
 * Updates the given stream identifier's cache with the provided raw_data.
 *
 * @param identifier A string which is used to identify a stream
 * @param raw_data A piece of raw PCM data which will is appended to the cache
 */
void SimpleSampleCache::update(const string identifier, const string raw_data)
{
	map<string, cache_data_t*>::iterator iter = cache_data.find(identifier);

	if (iter != cache_data.end())
	{
			// Delete the cached data if it already exists
		prepare_data(iter);

		iter->second->data.append(raw_data);
	}
}

/**
 * Get a string which contains PCM data related to the given sample identifier.
 *
 * @param identifier A string which is used to identify our sample.
 * @return Our PCM data, represented as a string.
 */
string SimpleSampleCache::get_raw_data(const string identifier)
{
	map<string, cache_data_t*>::iterator iter = cache_data.find(identifier);

	if (iter != cache_data.end())
		return iter->first;

	return NULL;
}

/**
 * Sets the sample info data for the given cache entry.
 *
 * @param identifier Identifies which entry in the cache to set the info on
 * @param info A sample_info_t pointer that will describe this identifier
 */
void SimpleSampleCache::set_info(const string identifier, sample_info_t* info)
{
	map<string, cache_data_t*>::iterator iter = cache_data.find(identifier);

	if (iter != cache_data.end())
	{
		prepare_data(iter);

			// Updated it with new data
		iter->second->info = info;
	}
}

/**
 * Gets the sample_info_t* related to the given identifier - if it exists.
 *
 * @param identifier The identifier which is used to refer to this sample.
 * @return Pointer to the sample_info_t structure decribing this sample.
 */
sample_info_t* SimpleSampleCache::get_info(const string identifier)
{
	map<string, cache_data_t*>::iterator iter = cache_data.find(identifier);

	if (iter != cache_data.end())
	{
		if (iter->second != NULL && iter->second->info != NULL)
			return iter->second->info;
	}

	return NULL;
}

/**
 * Cleans the specified iterator for erasing from our cache_data.
 *
 * @param iter The iterator that we would like to be cleaned.
 */
void SimpleSampleCache::clean_data(map<string,cache_data_t*>::iterator iter)
{
	if (iter->second != NULL)
	{
		if (iter->second->info != NULL)
			delete iter->second->info; // Delete our cached sample info.

		delete iter->second; // Delete our cache_data_t structure
	}
}

/**
 * Receives an iterator and modifies it to be in working order.
 *
 * @param iter An iterator from our cache_data variable.
 */
void SimpleSampleCache::prepare_data(map<string, cache_data_t*>::iterator iter)
{			// Delete the cached data if it already exists
	if (iter->second == NULL)
	{
		iter->second = new cache_data_t;

		iter->second->data = string("");
		iter->second->info = NULL;
	}
}

SimpleSampleCache::SimpleSampleCache()
{
}

SimpleSampleCache::~SimpleSampleCache()
{
}
