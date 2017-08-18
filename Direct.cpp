#include "Cache.h"
#include <math.h>
using namespace std;

/*
 * This function implements a Direct Mapped cache.
 * Given the state of the cache, and the address, this function
 * returns true if there is a cache hit, and false on a cache miss.
 * It also updates the tag in the appropriate cache entry.
 */

bool Cache::lookup(unsigned int addr, unsigned int unused) {

  // IMPLEMENT THIS FUNCTION!
	//get block size
	int block_size_expo = 0;
	int block_size_copy = blockSize;

	while(block_size_copy > 1){
		block_size_copy /= 2;
		block_size_expo++;
	}

	//eliminate block number
	addr = addr >> block_size_expo;

	//get cache number
	int cache_size_expo = 0;
	int cache_size_copy = cacheSize;

	while(cache_size_copy > 1){
		cache_size_copy /= 2;
		cache_size_expo++;
	}

	int valid_digit = pow(2, cache_size_expo) - 1;
	int cache_num = addr & valid_digit;

	// get tag
	int tag = addr >> cache_size_expo;

	
	if((*(entries+cache_num)).tag == tag){
		return true;
	}
	(*(entries+cache_num)).tag = tag;
  return false;

}



