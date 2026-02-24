#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

queue<int> buffer;
const int SIZE = 3;

mutex mtx;
condition_variable not_full;
condition_variable not_empty;

void producer()
{
    for(int i = 1; i <= 5; i++)
    {
        unique_lock<mutex> lock(mtx);

        while(buffer.size() == SIZE)
            not_full.wait(lock);                  // wait until space

        buffer.push(i);
        cout << "Produced: " << i << endl;

        not_empty.notify_one();                 // tell consumer
    }
}

void consumer()
{
    for(int i = 1; i <= 5; i++)
    {
        unique_lock<mutex> lock(mtx);

        while(buffer.empty())
            not_empty.wait(lock);             // wait until item

        int val = buffer.front();
        buffer.pop();
        cout << "   Consumed: " << val << endl;

        not_full.notify_one();                  // tell producer
    }
}

int main()
{
    thread p(producer);
    thread c(consumer);

    p.join();
    c.join();
}
