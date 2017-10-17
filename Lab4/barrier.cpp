/*!
*	Name: Darren Kelly
*	Date: 17/10/2017
*       Purpose: To create a reusable barries for a thread.
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>



int c=0; // keep a count of the threads
int n=3; // declare number of threads


/**< A method for an reusable barrier. */
void lunchBreak(std::shared_ptr<Semaphore> mutex, std::shared_ptr<Semaphore> turnstileA, std::shared_ptr<Semaphore> turnstileB){
  mutex->Wait();
  c++;

  /**< A test to see if thread are apearing in the right order. */
  std::cout<<"Bob is gone to lunch" << " " << c << std::endl; 
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

int main(){
  /**< Crafting the Semaphore for reuseable barrier. */
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  std::shared_ptr<Semaphore> turnstileA( new Semaphore());
  std::shared_ptr<Semaphore> turnstileB( new Semaphore(1));

  /**< Crafting the threads */
  std::thread bob1(lunchBreak, mutex, turnstileA, turnstileB);
  std::thread bob2(lunchBreak, mutex, turnstileA, turnstileB);
  std::thread bob3(lunchBreak, mutex, turnstileA, turnstileB);
  
  /**< Launch the threads  */
  bob1.join();
  bob2.join();
  bob3.join();
  return 0;
}
