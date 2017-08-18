class CacheEntry {
 public:
  int tag;
  int time;
  int frequency;
  CacheEntry() {
    tag = -1;
    time = -1;
    frequency = 0;
  }
};

class Cache {
 public:
  int blockSize; // number of words per block
  int cacheSize; // number of blocks (cache lines) in the cache
  CacheEntry* entries; // the entries in the cache

  Cache(int b, int c) {
    blockSize = b;
    cacheSize = c;
    entries = new CacheEntry[c];
  }

  ~Cache() {
    delete[] entries;
  }

  bool lookup(unsigned int, unsigned int); // not implemented! 
};


