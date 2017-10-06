#include "Semaphore.h"
#include <iostream>
#include <thread>

int c=0;

void lunchBreak(std::shared_ptr<Semaphore> mutex){
  mutex->Wait();
      std::cout<<"Bob is gone to lunch" << " " << c << std::endl;
      c++;
  mutex->Signal();    
}

int main(void){
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  std::thread bob1(lunchBreak, mutex);
  std::thread bob2(lunchBreak, mutex);
  std::thread bob3(lunchBreak, mutex);
  /**< Launch the threads  */
  bob1.join();
  bob2.join();
  bob3.join();
  return 0;
}
