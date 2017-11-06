#include "Barrier.h"
#include <iostream>
#include <mutex>

void Barrier::reuseable_barrier(std::shared_ptr<Semaphore>mutex, std::shared_ptr<Semaphore>turnstileA,std::shared_ptr<Semaphore>turnstileB, int c, int n){
      mutex->Wait();
      c++;

      /**< A test to see if thread are apearing in the right order. */
      std::cout<<"Thread:" << " " << c << std::endl;
      if(c==n){
      	turnstileB->Wait();
      	turnstileA->Signal();
      }
      mutex->Signal();
      turnstileA->Wait();
      turnstileA->Signal();
      mutex->Wait();
      c--;
      if(c==0){
      	turnstileA->Wait();
      	turnstileB->Signal();
      }
      mutex->Signal();
      turnstileB->Wait();
      turnstileB->Signal();
}
