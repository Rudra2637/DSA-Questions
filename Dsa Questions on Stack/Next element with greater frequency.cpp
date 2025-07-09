#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        unordered_map<int,int>m;
        for(auto it:arr)m[it]++;
        int s = arr.size();
        
        vector<int>ans(s,-1);
        stack<int>st;
        st.push(arr[s-1]);
        
        for(int i=arr.size()-1;i >= 0;i--){
            while(!st.empty() && m[st.top()] <= m[arr[i]]) st.pop();
            
            if(!st.empty())ans[i] = st.top(); 
            
            st.push(arr[i]);
        }
        
        return ans;
    }
};
