#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class solution
{
    public:
        int celebrity_prob(vector<vector<int>> &m ,int n)
        {
            stack<int> s;
            for(int i = 0; i<n ;i++)
            {
                s.push(i);
            }

            while(s.size() > 1)
            {
                int a = s.top();
                s.pop();

                int b = s.top();
                s.pop();

                if(m[a][b] == 1)
                {
                    s.push(b);
                }
                else
                {
                    s.push(a);
                }
            }
            int candidate = s.top();

            int zerocount = 0;
            for(int i = 0 ; i < n ; i++)
            {
                if(m[candidate][i] == 0 )
                {
                    zerocount++;
                }
            }
            if(zerocount != n)
            {
                return -1;
            }

            int onecount = 0;
            for(int i =0 ;i<n;i++)
            {
                if(m[i][candidate] == 1)
                {
                    onecount++;
                }
            }
            if(onecount != n-1)
            {
                return -1;
            }

            return candidate;
        }
};

int main()
{
    solution s;
    int n = 3;
    vector<vector<int>> m;
    m = {{0,1,0},
         {0,0,1},
         {0,1,0}};

    cout<<"the celebrity is : "<<s.celebrity_prob(m,n)<<endl;
    return 0;
}