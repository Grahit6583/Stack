// FIND MINIMUM COST TO MAKE STRING VALID
#include<iostream>
#include<stack>

using namespace std;

int mincost(string &s)
{
    if(s.length()%2 == 1)
    {
        return -1;
    }
    else
    {
        stack<char> s1;
        for(int i =0 ;i<=s.length();i++)
        {
            char ch = s[i];
            if(ch == '{')
            {
                s1.push(ch);
            }
            else
            {
                if(!s1.empty() && s1.top() == '{')
                {
                    s1.pop();
                }
                else
                {
                    s1.push(ch);
                }
            }
        }
        int a =0 ,b=0;
        while(s1.empty())
        {
            if(s1.top() == '{')
            {
                b++;
            }
            else
            {
                a++;
            }
        }
        
        int ans = ((a+1)/2) + ((b+1)/2);
        return ans;
    }
}

int main()
{
    string s1 = "{}}";
    int ans = mincost(s1);
    if(ans == -1)
    {
        cout<<"INVALID STRING"<<endl;
    }
    else
    {
        cout<<"MIN COST TO MAKE STR = "<<s1<<" VALID IS "<<ans<<endl;
    }
}