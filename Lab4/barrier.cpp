/*!
*	Name: Darren Kelly
*	Date: 17/10/2017
*       Purpose: To create a reusable barries for a thread.
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>



int c=0; // keep a count of the threads.
int n=3; // declare number of threads.
bool q = true; // condition to end while loop.


/**< A method for an reusable barrier. */
void reuseable_barrier(std::shared_ptr<Semaphore> mutex, std::shared_ptr<Semaphore> turnstileA, std::shared_ptr<Semaphore> turnstileB){
  while(q){
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
	q=false;
      }
      mutex->Signal();

      turnstileB->Wait();
      turnstileB->Signal();  
  }
}

int main(){
  /**< Creating the Semaphore for reuseable barrier. */
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  std::shared_ptr<Semaphore> turnstileA( new Semaphore());
  std::shared_ptr<Semaphore> turnstileB( new Semaphore(1));

  /**< Creating the threads */
  std::thread bob1(reuseable_barrier, mutex, turnstileA, turnstileB);
  std::thread bob2(reuseable_barrier, mutex, turnstileA, turnstileB);
  std::thread bob3(reuseable_barrier, mutex, turnstileA, turnstileB);
  
  /**< Launch the threads  */
  bob1.join();
  bob2.join();
  bob3.join();
  return 0;
}
