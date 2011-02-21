/* 
 * File:   simplesamplecache.hpp
 * Author: monokrome
 *
 * Created on February 21, 2011, 6:41 AM
 */

#ifndef SIMPLESAMPLECACHE_HPP
#define	SIMPLESAMPLECACHE_HPP

#include <string>
#include <map>
#include "samplecache.hpp"

typedef struct {
	string data; // The PCM data related to this specific audio cache
	sample_info_t* info; // Contains information regarding how to use data
} cache_data_t;

class SimpleSampleCache : public ISampleCache
{
protected:
	map<string, cache_data_t*> cache_data;

public:
	SimpleSampleCache();
	~SimpleSampleCache();

	/**
     * @param identifier The identifier of a specific peice of audio data.
     * @param raw_data The data that should be appended to this
     */
	virtual void set_data(string identifier, cache_data_t* data);
	virtual void update(string identifier, string raw_data);
	virtual void clear(string identifier);

	virtual string get_data(string identifier);
};

#endif	/* SIMPLESAMPLECACHE_HPP */
