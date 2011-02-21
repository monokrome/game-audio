/* 
 * File:   simplesamplecache.cxx
 * Author: Brandon "monokrome" Stoner
 *
 * Created on February 21, 2011, 6:40 AM
 */

#include <string>
#include "simplesamplecache.hpp"

using namespace std;

void SimpleSampleCache::set_info(string identifier, sample_info_t* info)
{
	map<string, cache_data_t*>::iterator iter = cache_data.find(identifier);

	if (iter != cache_data.end())
	{
		prepare_data(iter);

			// Updated it with new data
		iter->second->info = info;
	}
}

sample_info_t* SimpleSampleCache::get_info(string identifier)
{
	map<string, cache_data_t*>::iterator iter = cache_data.find(identifier);

	if (iter != cache_data.end())
	{
		if (iter->second != NULL && iter->second->info != NULL)
			return iter->second->info;
	}

	return NULL;
}

void SimpleSampleCache::update(string identifier, string raw_data)
{
	map<string, cache_data_t*>::iterator iter = cache_data.find(identifier);

	if (iter != cache_data.end())
	{
			// Delete the cached data if it already exists
		prepare_data(iter);

		iter->second->data.append(raw_data);
	}
}

void SimpleSampleCache::clear(string identifier)
{
	map<string, cache_data_t*>::iterator iter = cache_data.find(identifier);

	if (iter != cache_data.end())
	{
		delete iter->second->info; // Delete our cached sample info.
		delete iter->second; // Delete our cached data.

		cache_data.erase(iter);
	}
}

string SimpleSampleCache::get_data(string identifier)
{
	map<string, cache_data_t*>::iterator iter = cache_data.find(identifier);

	if (iter != cache_data.end())
		return iter->first;

	return NULL;
}

SimpleSampleCache::SimpleSampleCache()
{
}

SimpleSampleCache::~SimpleSampleCache()
{
}

/***
 * Receives an iterator and modifies it to be in working order.
 */
void prepare_data(map<string, cache_data_t*>::iterator iter)
{			// Delete the cached data if it already exists
	if (iter->second == NULL)
	{
		iter->second = new cache_data_t;
		iter->second->data = string("");
		iter->second->info = NULL;
	}
}
