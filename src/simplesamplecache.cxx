/* 
 * File:   simplesamplecache.cxx
 * Author: Brandon "monokrome" Stoner
 *
 * Created on February 21, 2011, 6:40 AM
 */

#include <string>
#include "simplesamplecache.hpp"

using namespace std;

void SimpleSampleCache::update(string identifier, string raw_data)
{
	cache_data[identifier].append(raw_data);
}

void SimpleSampleCache::clear(string identifier)
{
	cache_data[identifier].clear();
}

string SimpleSampleCache::get(string identifier)
{
	map<string, string>::iterator iter;

	iter = cache_data.find(identifier);

	if (iter != cache_data.end())
		return cache_data[identifier];

	return NULL;
}

SimpleSampleCache::SimpleSampleCache()
{
}

SimpleSampleCache::~SimpleSampleCache()
{
}
