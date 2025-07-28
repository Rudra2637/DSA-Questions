#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int cnt = 1;
        if(s == "")cnt = 0;

        int i = 0;
        for(int j=0;j<s.size();j++){
            
            if(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
                while(i <= j && st.find(s[j]) != st.end()){
                    st.erase(s[i]);
                    i++;
                }
            }
            st.insert(s[j]);
            int n = st.size();
            cnt = max(cnt,n);
        }
        return cnt;
    }
};
