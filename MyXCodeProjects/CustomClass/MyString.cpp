#include<cstring>
#include<iostream>
using namespace std;

class MyString
{
    char* data;
    
public:
    MyString(){ //Default constructor
        data = new char[1];
        data[0] = '\0';
        cout<<"Default Cinstructor\n";
    }
    
    MyString(const char* str) //Parameterized Constructor
    {
        data = new char[strlen(str)+1];
        strcpy(data, str);
        cout<<"Parameterized Constructor\n";
    }
    
    MyString(MyString& myString)    //Copy Constructor
    {
        data = new char[strlen(myString.data)+1];
        strcpy(data, myString.data);
        cout<<"Copy Constructor\n";
    }
    
    MyString& operator=(MyString& myString) //Copy Assignment Operator
    {
        if (this != &myString) {
                delete[] data; // Prevent memory leak
                data = new char[strlen(myString.data)+1];
                strcpy(data, myString.data);
            }
        cout<<"Copy Assignment Operator\n";
        return *this;
    }
    
    MyString(MyString&& myString) noexcept //Move Constructor, if noexcept is not wriiten then move constructor will act like copy semantics(not move semantics) which is inefficient.
    {
        //data = new char[strlen(myString.data)+1];
        data = myString.data;
        myString.data = nullptr;
        cout<<"Move Constructor\n";
    }
    
    MyString& operator=(MyString&& myString) noexcept   //Move Assignment Operator
    {
        if(this != &myString)
        {
            delete[] data;
            //data = new char[strlen(myString.data)+1];
            data = myString.data;
            //strcpy(data, myString.data);
            myString.data = nullptr;
        }
        cout<<"Move Assignment Operator\n";
        return *this;
    }
    
    ~MyString()
    {
        delete[] data;
        cout<<"Destructor\n";
    }
    
    MyString operator+(const MyString& myString) const{
        size_t newLen = strlen(data)+strlen(myString.data);
        char* newData = new char[newLen+1];
        strcpy(newData, data);
        strcat(newData, myString.data);
        MyString result(newData);
        delete[] newData;
        return result;
    }
    
};

//int main()
//{
//    MyString s1("Anchit");
//    MyString s2 = std::move(s1);
//    MyString s3(s2);
//    s3 = std::move(s2);
//    MyString s4(" Pathak");
//    MyString s5;
//    s5 = s4;
//    MyString s6;
//    return 1;
//}
