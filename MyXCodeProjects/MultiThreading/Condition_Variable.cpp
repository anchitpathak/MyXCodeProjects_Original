#include<iostream>
#include<chrono>
#include<condition_variable>
#include<mutex>
#include<thread>
using namespace std;

condition_variable cv;
mutex m1;
int num = 0;

void printOdd(int n)
{
    unique_lock<mutex> ul(m1);
    while(num<n)
    {
        cv.wait(ul, []{return (num%2 == 0)? true : false;});
        //if(num<n)
            cout<<this_thread::get_id()<<" "<<++num<<endl;
        cv.notify_one();
    }
}

void printEven(int n)
{
    unique_lock<mutex> ul(m1);
    while(num<n)
    {
        
        cv.wait(ul, []{return (num%2 == 1)? true : false;});
        //if(num<n)
            cout<<this_thread::get_id()<<" "<<++num<<endl;
        cv.notify_one();
    }
}

//int main()
//{
//    thread t1(printOdd, 3);
//    thread t2(printEven, 4);
//    t1.join();
//    t2.join();
//    this_thread::sleep_for(chrono::seconds(3));
//    cout<<"End of Program";
//    return 1;
//}
