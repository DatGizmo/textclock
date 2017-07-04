CPP=g++
CFLAGS=-std=c++11
DEPS=strings.h clock.h fuzzyclock.h qlock.h 
OBJ=strings.cpp clock.cpp fuzzyclock.cpp qlock.cpp textclock.cpp
BINS=textclock

%.o: %cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CFLAGS)

textclock: $(OBJ)
	$(CPP) -o $@ $^ $(CFLAGS)

all: textclock

clean: 
	rm -f $(BINS) *.o
