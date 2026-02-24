#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <semaphore>

using namespace std;

queue<int> buffer;
const int SIZE = 3;

counting_semaphore<3> notfull(SIZE);           // space available
counting_semaphore<3> full(0);              // item available

mutex mtx;

void producer()
{
    for(int i = 1; i <= 5; i++)
    {
        notfull.acquire();      // wait if buffer is full

        mtx.lock();
        buffer.push(i);
        cout << "Produced: " << i << endl;
        mtx.unlock();

        full.release();        // signal item added
    }
}

void consumer()
{
    for(int i = 1; i <= 5; i++)
    {
        full.acquire();       // wait if buffer empty

        mtx.lock();
        int val = buffer.front();
        buffer.pop();
        cout << "   Consumed: " << val << endl;
        mtx.unlock();

        notfull.release();     // signal space available
    }
}

int main()
{
    thread p(producer);
    thread c(consumer);

    p.join();
    c.join();

    return 0;
}
