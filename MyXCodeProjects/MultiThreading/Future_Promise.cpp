#include<iostream>
#include<thread>
#include<chrono>
#include<future>
using namespace std;

void add(promise<int>&& res, int a, int b)
{
    int c = a+b;
    this_thread::sleep_for(chrono::seconds(3));
    res.set_value(c);
}

//int main()
//{
//    promise<int> p;
//    future<int> f = p.get_future();
//    thread t1(add, move(p), 4, 3);
//    cout<<"Waiting..";
//    cout<<f.get()<<endl;
//    return 1;
//}
