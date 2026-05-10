#include<iostream>
#include<mutex>
using namespace std;

class Singleton
{
private:
    Singleton(){}
    static Singleton* obj;
    static mutex mtx;
public:
    static Singleton*  getObj()
    {
        if(obj==nullptr)
        {
            if(mtx.try_lock())
            {
                if(obj==nullptr)
                {
                    obj = new Singleton();
                }
                mtx.unlock();
            }
        }
        return obj;
    }
    Singleton(const Singleton&) = delete;
//    {
//        cout<<"Copy constructor"<<endl;
//    }
    Singleton& operator=(const Singleton&) = delete;
//    {
//        cout<<"Copy Assignment operator";
//        return *this;
//    }
};
Singleton* Singleton::obj = nullptr;
mutex Singleton::mtx;
//int main()
//{
////    Singleton* obj = Singleton::getObj();
////    cout<<obj<<endl;
////    Singleton* obj1 = Singleton::getObj();
////    cout<<obj<<" "<<obj1<<endl;
//    Singleton* obj = Singleton::getObj();
//    delete obj;
//    return 1;
//}
