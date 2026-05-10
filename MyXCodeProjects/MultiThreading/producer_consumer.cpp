#include<iostream>
#include<condition_variable>
#include<thread>
#include<mutex>
using namespace std;

condition_variable cv_1;
mutex m2;
deque<int> buffer;
int maxBufferSize = 10;
void producer(int val)
{
    while(val)
    {
        unique_lock<mutex> ul(m2);
        cv_1.wait(ul, []{return buffer.size() < maxBufferSize;});
        cout<<"Produced: "<<val<<endl;
        buffer.push_back(val--);
        //m2.unlock();
        cv_1.notify_one();
    }
}
void consumer()
{
    while(true)
    {
        unique_lock<mutex> ul(m2);
        cv_1.wait(ul, []{return buffer.size() > 0;});
        int val = buffer.back();
        buffer.pop_back();
        cout<<"Consumed: "<<val<<endl;
        //m2.unlock();
        cv_1.notify_one();
    }
}
//int main()
//{
//    thread t1(producer, 100);
//    thread t2(consumer);
//    t1.join();
//    t2.join();
//    cout<<"---End---";
//    return 1;
//}

