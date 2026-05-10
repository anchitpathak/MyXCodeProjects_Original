#include<vector>
#include<iostream>
using namespace std;
//bool validPallidrome(string &s)
//{
//    int length = s.size();
//    for(int i = 0, j = length-1; i<length&&j>-1;i++, j--)
//    {
//        if(((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))&&((s[j]>=65&&s[j]<=90)||(s[j]>=97&&s[j]<=122)))
//        {
//            char a = (char)tolower(s[i]);
//            char b = (char)tolower(s[j]);
//            if(a==b)
//            {
//                i++;
//                j--;
//            }
//            else
//                return false;
//            
//        }
//        if(!((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)))
//            i++;
//        if(!((s[j]>=65&&s[j]<=90)||(s[j]>=97&&s[j]<=122)))
//            j--;
//    }
//    if(i==length&&j==-1)
//        return true;
//    else
//        return false;
//}
//int main()
//{
//    //string s = "A man, a plan, a canal: Panama";
//    //cout<<validPallidrome(s);
//    return 1;
//}
