#include<iostream>
#include<bits/stdc++.h>
#define MAX 20

using namespace std;

class solution
{
    private:
    vector<int> prev_smaller(int* arr,int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = 0; i < n  ; i++)
        {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> next_smaller(int* arr,int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = n-1; i >= 0 ; i--)
        {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largest_area(int* heights , int n)
    {
        //int n = heights.size();

        vector<int> next(n);
        next = next_smaller(heights,n);

        vector<int> prev(n);
        prev = prev_smaller(heights,n);

        int area = INT_MIN;
        for(int i =0 ;i<n;i++)
        {
            if(next[i] == -1)
            {
                next[i] = n;
            }
            int l = heights[i];
            int b = next[i] - prev[i] - 1;


            int new_area = l*b;
            area = max(area,new_area);
        }
        return area;
    }  

    public:
        int max_rectangle(int M[MAX][MAX] , int n ,int m)
        {
            int area = largest_area(M[0],m);
            for(int i =1 ; i<n ;i++)
            {
                for(int j = 0 ;j<m ;j++)
                {
                    if(M[i][j] != 0)
                    {
                        M[i][j] = M[i][j] + M[i-1][j];
                    }
                    else
                    {
                        M[i][j] = 0;
                    }
                }
            area = max(area,largest_area(M[i],m));
            }
            return area;
        }
};

int main()
{
   solution s;
   int n=4,m=4;
   int M[MAX][MAX] = {{0,1,1,0},
                  {1,1,1,1},
                  {1,1,1,1},
                  {1,1,0,0}};
    cout<<"THE LARGEST AREA OF RECTANGLE IS : "<<s.max_rectangle(M,n,m);
    return 0;
}