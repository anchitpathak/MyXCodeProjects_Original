
#include<stack>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int solve(vector<string> &vs)
{
    stack<int> s;
    int c;
    for(auto i: vs)
    {
        char ch='0';
        if(i=="+"||i=="-"||i=="*"||i=="/")
            ch = i[0];
        int a,  b;
        switch(ch)
        {
            case '+' :
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                c = a+b;
                s.push(c);
                break;
            case '-' :
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                c = a-b;
                s.push(c);
                break;
            case '*' :
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                c = a*b;
                s.push(c);
                break;
            case '/' :
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                c = a/b;
                s.push(c);
                break;
            default:
                s.push(stoi(i));
                break;
        }
    }
    
    return s.top();
            
}
//int main()
//{
//    vector<string> vs;
//    vs = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
//    cout<<solve(vs);
//    return 1;
//}
