#include<iostream>
using namespace std;

class Base{
private:
    int i, j;
public:
    Base(int a = 0, int b = 0)
    {
        i = a;
        j = b;
    }
    Base operator+(Base const& obj)
    {
        Base res;
        res.i = i+obj.i;
        res.j = j+obj.j;
        return res;
    }
    void print()
    {
        cout<<i<<" "<<j;
    }
    
};

//int main()
//{
//    Base a(10, 20), b(5, 15), c;
//    c = a+b;
//    c.print();
//    return 1;
//}

//class Complex {
//private:
//    int real, imag;
//
//public:
//    Complex(int r = 0, int i = 0)
//    {
//        real = r;
//        imag = i;
//    }
//
//    // This is automatically called when '+' is used with
//    // between two Complex objects
//    Complex operator+(Complex const& obj)
//    {
//        Complex res;
//        res.real = real + obj.real;
//        res.imag = imag + obj.imag;
//        return res;
//    }
//    void print() { cout << real << " + i" << imag << '\n'; }
//};
//
//int main()
//{
//    Complex c1(10, 5), c2(2, 4);
//    Complex c3 = c1 + c2;
//    c3.print();
//}
