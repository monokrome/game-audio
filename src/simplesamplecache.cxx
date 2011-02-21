/* 
 * File:   simplesamplecache.cxx
 * Author: Brandon "monokrome" Stoner
 *
 * Created on February 21, 2011, 6:40 AM
 */

#include <string>
#include "simplesamplecache.hpp"

using namespace std;

void SimpleSampleCache::set_data(string identifier, cache_data_t* data)
{
	map<string, cache_data_t*>::iterator iter = cache_data.find(identifier);

	if (iter != cache_data.end())
	{
			// Delete the cached data if it already exists
		if (iter->second != NULL)
			delete iter->second;

			// Updated it with new data
		iter->second = data;
	}
}

void SimpleSampleCache::update(string identifier, string raw_data)
{
	map<string, cache_data_t*>::iterator iter = cache_data.find(identifier);

	if (iter != cache_data.end())
	{
			// Delete the cached data if it already exists
		if (iter->second != NULL)
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
