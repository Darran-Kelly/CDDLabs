/*!
*	Name: Darren Kelly
*	Date: 17/10/2017
*/

#include <mutex>
#include <condition_variable>

class Semaphore
{
private:
    unsigned int m_uiCount; /*!< Holds the Semaphore count */
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    Semaphore(unsigned int uiCount=0)
          : m_uiCount(uiCount) { };
    void Wait();
    void Signal();
};
