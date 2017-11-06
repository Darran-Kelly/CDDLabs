/*!
*	      Name: Darren Kelly
*	      Date: 17/10/2017
*       Purpose: To create a reusable barries for a thread.
*/
#include "Barrier.h"
#include <iostream>
#include <thread>



int c=0; // keep a count of the threads.
int n=4; // declare number of threads.





int main(){
  /**< Creating the Semaphore for reuseable barrier. */
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));
  std::shared_ptr<Semaphore> turnstileA(new Semaphore());
  std::shared_ptr<Semaphore> turnstileB(new Semaphore(1));

  /**< Creating the threads */
  std::thread bob1(Barrier::reuseable_barrier, mutex, turnstileA, turnstileB, c, n);
  std::thread bob2(Barrier::reuseable_barrier, mutex, turnstileA, turnstileB, c, n);
  std::thread bob3(Barrier::reuseable_barrier, mutex, turnstileA, turnstileB, c, n);
  std::thread bob4(Barrier::reuseable_barrier, mutex, turnstileA, turnstileB, c, n);

  /**< Launch the threads  */
  bob1.join();
  bob2.join();
  bob3.join();
  bob4.join();
  return 0;
}
