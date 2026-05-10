#include<iostream>
#include<chrono>
#include<thread>
#include<future>
using namespace std;
using namespace std::chrono;
typedef long int li;

li oddSum(int& start, int& end)
{
    this_thread::sleep_for(chrono::seconds(3));
    li sum = 0;
    for(int i = start; i<=end; i++)
    {
        if(i&1)
        {
            sum += i;
        }
    }
    return sum;
}

//int main()
//{
//    future<li> res = async(launch::deffered, oddSum, 0, 190000);
//    cout<<"Waiting..."<<endl;
//    return 0;
//}
