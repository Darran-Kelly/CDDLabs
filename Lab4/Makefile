#	Name: Darren Kelly
#	Date: 17/10/2017


#Declaring flags.
CC=g++
CFLAGS= -std=c++11 -pthread -I.
CPPFILES = barrier.cpp Semaphore.cpp
HFILES = Semaphore.h
OFILES = barrier.o Semaphore.o

# looks to see if file is up to date. If not, recompile.
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

#Compile & make executable.
ALL: $(OFILES) 
	$(CC) -o go $(OFILES) $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

# removes all object files.
CLEAN:
	rm *.o
