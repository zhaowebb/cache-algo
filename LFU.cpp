#include "Cache.h"
#include <limits>
#include <math.h>
using namespace std;
int ones_counter(int frequency){
	int num = 0;
	while(frequency > 0){
		num += frequency & 1;
		frequency >>= 1;
	}
	return num;
}
/*
 * This function implements a Fully Associative cache using LFU.
 */
bool Cache::lookup(unsigned int addr, unsigned int time) {

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

	
	// get tag
	
	int tag = addr;

	for(int k = 0; k < cacheSize; k++){
		(*(entries+k)).frequency = (*(entries+k)).frequency & 255;
		(*(entries+k)).frequency = (*(entries+k)).frequency << 1;
	}

	for(int i = 0; i < cacheSize; i++){
		// tag has already in cache
		if((*(entries+i)).tag == tag){
			(*(entries+i)).frequency += 1;
			(*(entries+i)).time = time;
			return true;
		}
		// tag is not in cache but there is available space
		else if((*(entries+i)).tag == -1){
			(*(entries+i)).tag = tag;
			(*(entries+i)).time = time;
			(*(entries+i)).frequency += 1;
			return false;
		}
	}

	//tag is not in space and the cache is full;

	int lfu_index = 0;
	int num_ones = 9;
	

	for(int j = 0; j < cacheSize; j++){
		int ones = ones_counter((*(entries+j)).frequency);
		if(ones == num_ones){
			// is_tied = true;
			if((*(entries+j)).time < (*(entries+lfu_index)).time){
				lfu_index= j;
			}
		}
		else if(ones < num_ones){
			// is_tied = false;
			lfu_index = j;
			num_ones = ones;
		}
	}


	(*(entries+lfu_index)).tag = tag;
	(*(entries+lfu_index)).time = time;
	(*(entries+lfu_index)).frequency = 1;
	
  return false;

}



