#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void add(int a, int b, int &c)
{
    c = a+b;
}
void add_by_Pointer(int a, int b, int *c)
{
    *c = a+b;
}

void add_by_Reference(int a, int b, int &c)
{
    //this_thread::sleep_for(chrono::seconds(20));
    c = a+b;
}


void add_2x(vector<int> v, int &res)
{
    int sum = 0;
    
    for(int i = 0;i<v.size();i++)
    {
        v[i] = v[i]*2;
        sum += v[i];
    }
    res = sum;
}

void add_arr(int arr[], int &res, int n)
{
    int sum = 0;
    for(int i =0;i<n;i++)
    {
        arr[i] = arr[i]*2;
        sum += arr[i];
    }
    res = sum;
}

//int main()
//{
//    int c;
//    int a[2];
//    try{
//        cout<<a[2];
//    }catch(...)
//    {
//        cout<<"Hello, Caught";
//    }
//    
//    add(5, 4, c);
//    int d;
//    thread t1(add_by_Reference, 6, 5, ref(d));
//    cout<<d<<".. ";
//    vector<int> v;
//    v.push_back(2);
//    v.push_back(3);
//    int res;
//    add_2x(v,res);
//    int arr[2] = {6, 7};
//    int op;
//    add_arr(arr, op, 2);
//    cout<<c<<" "<<d<<" "<<res<<" "<<op;
//    return 1;
//}
