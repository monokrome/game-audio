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
	sample_info_t info; // Contains information regarding how to use data
} cache_data_t;

class SimpleSampleCache : public ISampleCache
{
private:
	void clean_data(map<string, cache_data_t*>::iterator iter);
	void prepare_data(map<string, cache_data_t*>::iterator iter);

protected:
	map<string, cache_data_t*> cache_data;

public:
	SimpleSampleCache();
	~SimpleSampleCache();

	virtual void clear(const string identifier) = 0;
	virtual void flush();

	virtual void update(const string identifier, const string raw_data) = 0;
	virtual string get_raw_data(const string identifier) = 0;

	virtual void set_info(const string identifier, sample_info_t* info) = 0;
	virtual sample_info_t get_info(const string identifier);
};

#endif

