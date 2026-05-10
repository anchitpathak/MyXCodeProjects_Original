#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool checkBalaced(char c[])
{
    stack<char> st;
    for(int i =0;c[i]!='\0';i++)
    {
        if(c[i]=='{'||c[i]=='['||c[i]=='(')
        {
            st.push(c[i]);
            continue;
        }
        else if(c[i]=='}'||c[i]==']'||c[i]==')')
        {
            char tempC = st.top();
            if(c[i]=='}'&&tempC=='{')
            {
                st.pop();
                continue;
            }
            else if(c[i]==']'&&tempC=='[')
            {
                st.pop();
                continue;
            }
            else if(c[i]==')'&&tempC=='(')
            {
                st.pop();
                continue;
            }
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}
//int main()
//{
//    char c[10] = {'{', '[',']','(', ')'};
//    cout<<checkBalaced(c);
//    return 1;
//    
//}

