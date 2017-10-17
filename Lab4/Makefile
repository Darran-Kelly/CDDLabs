#	Name: Darren Kelly
#	Date: 17/10/2017

CC=g++
CFLAGS= -std=c++11 -pthread -I.
CPPFILES = barrier.cpp Semaphore.cpp
HFILES = Semaphore.h

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(CPPFILES).o $(HFILES).o
	$(CC) -o go $(CPPFILES).o $(HFILES).o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

CLEAN:
	rm *.o
