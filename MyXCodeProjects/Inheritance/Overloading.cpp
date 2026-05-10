#include<iostream>
using namespace std;

class Base
{
public:
    int func()
    {
        cout<<"I am Base func()"<<endl;
        return 1;
    }
    void func(double d)
    {
        cout<<"I am Base func(double d)"<<endl;
    }
};
class Derive : public Base{
    
public:
    using Base::func;
    void func(int x)
    {
        cout<<"I am derived class overloaded func(int x)"<<endl;
    }
};
//int main()
//{
//    int a = 10;
//    Derive d;
//    Base b;
//    Base *p;
//    p = &d;
//    p->func();
//    p->func(1.1);
//    p = &b;
//    p->func();
//    d.func(a);
//    d.func();
//    d.func(1.1);
//    return 1;
//    
//}
