#include "Semaphore.h"
#include <mutex>

class Barrier{
public:
  int c;
  int n;
  static void reuseable_barrier(std::shared_ptr<Semaphore>, std::shared_ptr<Semaphore>, std::shared_ptr<Semaphore>, int, int);
};
