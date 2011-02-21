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
private:
	virtual void prepare_data(map<string, cache_data_t*>::iterator iter);

protected:
	map<string, cache_data_t*> cache_data;

public:
	SimpleSampleCache();
	~SimpleSampleCache();

	virtual void update(string identifier, string raw_data);
	virtual void clear(string identifier);
	virtual string get_data(string identifier);

	virtual void set_info(string identifier, sample_info_t* info);
	virtual sample_info_t* get_info(string identifier);
};

#endif	/* SIMPLESAMPLECACHE_HPP */
