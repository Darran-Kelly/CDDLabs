#	Name: Darren Kelly
#	Date: 17/10/2017


#Declaring flags.
CC=g++
CFLAGS= -std=c++11 -pthread -I.
CPPFILES = Main.cpp Barrier.cpp Semaphore.cpp
HFILES = Semaphore.h Barrier.h


# looks to see if file is up to date. If not, recompile.
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

#Compile & make executable.
ALL: Main.o Barrier.o Semaphore.o
	$(CC) -o go Semaphore.o  Barrier.o Main.o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

# removes all object files.
CLEAN:
	rm *.o
