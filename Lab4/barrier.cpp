#include "Semaphore.h"
#include <iostream>
#include <thread>



int c=0; // keep a count of the threads
int n=3; // declare number of threads

void lunchBreak(std::shared_ptr<Semaphore> mutex, std::shared_ptr<Semaphore> barries, std::shared_ptr<Semaphore> turnstile){
  mutex->Wait();
  c++;
  std::cout<<"Bob is gone to lunch" << " " << c << std::endl;
  if(c==n){
    turnstile->Wait();
    barries->Signal();
  }
  mutex->Signal();
  
  barries->Wait();
  barries->Signal();

  mutex->Wait();
  c--;
  if(c==0){
    barries->Wait();
    turnstile->Signal();
  }
  mutex->Signal();
  
  turnstile->Wait();
  turnstile->Signal();
  
}

int main(){
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  std::shared_ptr<Semaphore> barries( new Semaphore());
  std::shared_ptr<Semaphore> turnstile( new Semaphore(1));
  std::thread bob1(lunchBreak, mutex, barries, turnstile);
  std::thread bob2(lunchBreak, mutex, barries, turnstile);
  std::thread bob3(lunchBreak, mutex, barries, turnstile);
  /**< Launch the threads  */
  bob1.join();
  bob2.join();
  bob3.join();
  return 0;
}
