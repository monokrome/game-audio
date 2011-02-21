/* 
 * File:   simplesamplecache.hpp
 * Author: monokrome
 *
 * Created on February 21, 2011, 6:41 AM
 */

#ifndef SIMPLESAMPLECACHE_HPP
#define	SIMPLESAMPLECACHE_HPP

#include "samplecache.hpp"

class SimpleSampleCache : public ISampleCache
{
public:
	SimpleSampleCache();
	~SimpleSampleCache();

	virtual void update(string identifier, string raw_data);
	virtual void clear(string identifier);
	virtual string get(string identifier);
};

#endif	/* SIMPLESAMPLECACHE_HPP */
