#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch == '(')st.push(ch);
            else if(ch == ')'){
                if(st.empty()){
                    s.erase(i,1);
                    i--;
                }
                else if(st.top() == '(')st.pop();
            }
        }
       
        if(!st.empty()){
            int j=s.size()-1;
            while(!st.empty()){
                if(s[j] == st.top()){
                     s.erase(j,1);
                    st.pop();
                }
                else{
                    j--;
                }
                if(j<0)break;
            }
        }
        return s;
    }
};