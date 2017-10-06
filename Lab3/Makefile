
ODIR=obj
LDIR =../lib
DEBUG=-debug

Signal: Signal Semaphore.h Semaphore.cpp signal.cpp 
	g++ -std=c++11 -pthread -o Signal Semaphore.cpp signal.cpp Semaphore.h

Debug: DEBUG = -debug
	Debug: Signal

.PHONY: clean


clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
