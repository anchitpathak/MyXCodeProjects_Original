#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

mutex m7, m8;
int count1 = 10;
condition_variable cv7;

void func1()
{
    while(count1>0)
    {
        count1--;
        
        std::unique_lock<std::mutex> lock1(m7, std::defer_lock);
        cout<<"Waiting for m8"<<endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        std::unique_lock<std::mutex> lock2(m8, std::defer_lock);
        cout<<"Wait over for m8"<<endl;

            // 🔒 Lock both mutexes atomically and safely
        std::lock(lock1, lock2);
        cout<<this_thread::get_id()<<" "<<"Hi"<<endl;
    }
    
}

void func2()
{
    while(count1>0)
    {
        count1--;
        
        std::unique_lock<std::mutex> lock1(m8, std::defer_lock);
        cout<<"Waiting for m7"<<endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        std::unique_lock<std::mutex> lock2(m7, std::defer_lock);
        cout<<"Wait over for m7"<<endl;
            // 🔒 Lock both mutexes atomically and safely
        std::lock(lock1, lock2);
        cout<<this_thread::get_id()<<" "<<"Hello"<<endl;
    }
}
//int main()
//{
//    thread t1(func1);
//    thread t2(func2);
//    t1.join();
//    t2.join();
//    return 1;
//}
