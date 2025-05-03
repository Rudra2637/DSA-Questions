#include<bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(vector<int>& arr) {
    // write code here
    stack<int>st;
    vector<int>ans;
    st.push(0);
    ans.push_back(1);
    for(int i= 1 ;i<arr.size();i++){
        int cnt = 0;
        
        while(!st.empty() && arr[st.top()] <= arr[i])st.pop();
        
        if(!st.empty()){
            cnt = i - st.top();
            ans.push_back(cnt);
        }
        
        else ans.push_back(i+1);
        
        
        st.push(i);
    }
    return ans;
}