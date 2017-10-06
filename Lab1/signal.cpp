#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout <<"I ";
  std::cout << "must ";
  theSemaphore->Wait();
  std::cout << "print ";
  std::cout << "first"<<std::endl;
}

void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Signal(); 
  std::cout <<"This ";
  std::cout << "will ";
  theSemaphore->Wait();
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
  theSemaphore->Signal();
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
