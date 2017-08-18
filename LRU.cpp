#include "Cache.h"
#include <math.h>
#include <queue>
#include <limits>
using namespace std;

/*
 * This function implements a Fully Associative cache using LRU.
 */
bool Cache::lookup(unsigned int addr, unsigned int time) {

  // IMPLEMENT THIS FUNCTION!
	//populate a priority queue to track the least recently used
	

	//get block size
	int block_size_expo = 0;
	int block_size_copy = blockSize;

	while(block_size_copy > 1){
		block_size_copy /= 2;
		block_size_expo++;
	}

	//eliminate block number
	addr = addr >> block_size_expo;

	
	// get tag

	int tag = addr;

	for(int i = 0; i < cacheSize; i++){
		// tag has already in cache
		if((*(entries+i)).tag == tag){
			(*(entries+i)).time = time;
			return true;
		}
		// tag is not in cache but there is available space
		else if((*(entries+i)).tag == -1){
			(*(entries+i)).tag = tag;
			(*(entries+i)).time = time;
			return false;
		}
	}

	//tag is not in space and the cache is full;
	int ind = 0;
	int lru = numeric_limits<int>::max();

	for(int i = 0; i < cacheSize; i++){
		if((*(entries+i)).time < lru){
			lru = (*(entries+i)).time;
			ind = i;
		}
	}

	(*(entries+ind)).tag = tag;
	(*(entries+ind)).time = time;
	
  return false;

}


