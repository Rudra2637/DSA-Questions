#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n);
        stack<int>st;
        reverse(nums.begin(),nums.end());
        for(int i=0;i<n;i++)st.push(nums[i]);
        reverse(nums.begin(),nums.end());
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty())temp[i]=-1;
            else temp[i]=st.top();

            st.push(nums[i]);
        }
        
        return temp;
    }
};