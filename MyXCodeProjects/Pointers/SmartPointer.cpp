#include<iostream>
//#include <bits/stdc++.h>
using namespace std;

class SmartPointer
{
    string pointerType;
public:
    SmartPointer(string name)
    {
        pointerType = name;
    }
    void greetMe()
    {
        cout<<"Hello "<<pointerType<<endl;
    }
};

//int main()
//{
//    unique_ptr<SmartPointer> up = make_unique<SmartPointer>("Unique_Pointer");
//    unique_ptr<SmartPointer> up1 = move(up);
//    up1->greetMe();
//
//    shared_ptr<SmartPointer> sp = make_shared<SmartPointer>("Smart Pointer");
//    shared_ptr<SmartPointer> sp1 = sp;
//    sp->greetMe();
//    sp1->greetMe();
//    cout<<sp.use_count();
//    int a = 10;
//    shared_ptr<int> sp2 = make_shared<int>(a);
//    shared_ptr<int> sp3 = make_shared<int>(a);
//    int *p = &a;
//    int *p1 = &a;
//    cout<<sp3.use_count()<<endl;
//    cout<<sp<<" "<<sp1<<endl;
//    cout<<sp2<<" "<<sp3<<endl;
//    cout<<p<<" "<<p1<<" "<<&a;
//    //weak_ptr<SmartPointer> wp = ();
//    return 0;
//}
//int main() {
//    
//    // Pointer declaration
//    auto_ptr<int> ptr1(new int(10));
//    cout << *ptr1 << endl;
//    
//    // Transfer ownership to
//    // pointer ptr2,
//    auto_ptr<int> ptr2 = ptr1;
//    cout << *ptr2;
//    return 0;
//}
