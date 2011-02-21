/* 
 * File:   samplecache.hpp
 * Author: Brandon "monokrome" Stoner
 *
 * Created on February 21, 2011, 3:52 AM
 */

#ifndef AUDIOCACHE_HPP
#define	AUDIOCACHE_HPP

#include <string>
#include "audiosample.hpp"

using namespace std;

class ISampleCache
{
public:
	ISampleCache();
	~ISampleCache();

	virtual void clear(const string identifier) = 0;
	virtual void flush();

	virtual void update(const string identifier, const string raw_data) = 0;
	virtual string get_raw_data(const string identifier) = 0;

	virtual void set_info(const string identifier, sample_info_t* info) = 0;
	virtual sample_info_t* get_info(const string identifier);
};

#endif	/* AUDIOCACHE_HPP */
