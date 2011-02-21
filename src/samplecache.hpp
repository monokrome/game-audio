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

	virtual void update(string identifier, string raw_data) = 0;
	virtual void clear(string identifier) = 0;
	virtual string get_data(string identifier) = 0;
};

#endif	/* AUDIOCACHE_HPP */

