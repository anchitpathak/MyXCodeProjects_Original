#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

int data1 = 10;

mutex readerCountMutex;
mutex resourceMutex;
int readerCount = 0;
void read1()
{
    readerCountMutex.lock();
    readerCount++;
    if(readerCount==1)
        resourceMutex.lock();
    readerCountMutex.unlock();
    cout<<"Reader "<<readerCount<<": "<<data1<<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    readerCountMutex.lock();
    readerCount--;
    if(readerCount==0)
        resourceMutex.unlock();
    readerCountMutex.unlock();
}
void write1(int val)
{
    resourceMutex.lock();
    data1 = val;
    cout<<"Writer "<<data1<<endl;
    resourceMutex.unlock();
}
//int main()
//{
//    thread t1(read1);
//    thread t2(read1);
//    thread t3(write1, 100);
//    thread t4(read1);
//    t1.join();
//    t2.join();
//    t3.join();
//    t4.join();
//    return 1;
//}
