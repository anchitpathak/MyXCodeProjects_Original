#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
bool validPallidrome(string &s)
{
    int length = s.size();
    int i, j;
    bool res = true;
    for(i = 0, j = length-1; i<=j;)
    {
        if(((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))&&((s[j]>=65&&s[j]<=90)||(s[j]>=97&&s[j]<=122)))
        {
            char a = (char)tolower(s[i]);
            char b = (char)tolower(s[j]);
            if(a==b)
            {
                i++;
                j--;
                res = true;
            }
            else
                return false;
            continue;
        }
        if(s[i]==' '&&s[j]==' ')
            res = true;
        if(!((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)))
            i++;
        if(!((s[j]>=65&&s[j]<=90)||(s[j]>=97&&s[j]<=122)))
            j--;
    }
    return res;
}
//int main()
//{
////    string s = "A man, a plan, a canal: Panama";
////    cout<<static_cast<bool>(validPallidrome(s));
////    cout<<"Anchit";
//    
//    string s1 = " ";
//    cout<<static_cast<bool>(validPallidrome(s1));
//    cout<<"Anchit";
//    return 1;
//}


