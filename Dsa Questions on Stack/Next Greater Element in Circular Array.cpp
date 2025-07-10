#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        stack<int>st;
        int s = arr.size();
        vector<int>ans(s,-1);
        
        for(int i=s-1;i>=0;i--)st.push(arr[i]);
        
        for(int i = s-1;i>=0;i--){
            while(!st.empty() && st.top() <= arr[i])st.pop();
            
            if(!st.empty())ans[i] = st.top();
            
            st.push(arr[i]);
        }
        
        return ans;
        
    }
};
