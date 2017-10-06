
ODIR=obj
LDIR =../lib



Signal: Signal Semaphore.h Semaphore.cpp signal.cpp 
	g++ -std=c++11 -pthread -o Signal Semaphore.cpp signal.cpp Semaphore.h $(DEBUGFILE)

DEBUG: DEBUGFILE = -DDEBUG
DEBUG: Signal


.PHONY: clean


clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
