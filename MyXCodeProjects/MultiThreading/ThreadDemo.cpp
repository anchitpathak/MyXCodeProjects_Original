#include<thread>
#include<iostream>
#include<mutex>
using namespace std;
recursive_mutex m;
int cnt = 0;
void run(char c, int forTime)
{
    if(forTime-- == 0)
        return;
    m.lock();
    cout<<"Thread no. "<<c<<" "<<cnt++<<endl;
    run(c, forTime);
    m.unlock();
}

//int main()
//{
//    thread t1(run, '1', 5);
//    thread t2(run, '2', 5);
//    cout<<this_thread::get_id();
//    t1.join();
//    t2.join();
//    return 1;
//}
