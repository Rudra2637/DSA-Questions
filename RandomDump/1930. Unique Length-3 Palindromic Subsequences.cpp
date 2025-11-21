#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int>m;
        
        int cnt=0;
        for(int i=0;i<s.size();i++)m[s[i]]=i;
        
        for(int i=0;i<s.size();i++){
            int j =m[s[i]];
            if(i == j ||m[s[i]]==0)continue;
            else{
                unordered_set<char>st;
                for(int k = i+1;k < j;k++) st.insert(s[k]);
                
                m[s[i]] = 0;
                cnt += st.size();
            }
            
        }
        return cnt;
    }
};