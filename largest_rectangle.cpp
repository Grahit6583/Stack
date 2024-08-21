#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class solution
{
    private:
    vector<int> prev_smaller(vector<int> &arr,int n)
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
    vector<int> next_smaller(vector<int> &arr,int n)
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
    public:
    int largest_area(vector<int>& heights)
    {
        int n = heights.size();

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
};

int main()
{
    vector <int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);
    solution s;
    int ans = s.largest_area(heights);
    cout<<"THE LARGEST AREA IS : "<<ans<<endl;
}