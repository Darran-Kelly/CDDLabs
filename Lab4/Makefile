CC=g++
CFLAGS= -std=c++11 -pthread -I.

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: barrier.o Semaphore.o
	$(CC) -o go Semaphore.o barrier.o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

CLEAN:
	rm *.o
