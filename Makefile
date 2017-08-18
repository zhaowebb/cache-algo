CC = clang
ARGS = -Wall

all: LRU Direct LFU

LRU:
	c++ -std=c++11 -o LRU FullDriver.cpp LRU.cpp

Direct:
	c++ -std=c++11 -o Direct Driver.cpp Direct.cpp

LFU:
	c++ -std=c++11 -o LFU FullDriver.cpp LFU.cpp

clean: 
	rm -rf LRU Direct LFU *.o

