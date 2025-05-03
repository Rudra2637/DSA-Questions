#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string& s) {
    // code here
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')st.push(s[i]);
        
        else{
            if(!st.empty()){
               
                char ch = st.top();
               
                if(ch == '(' && s[i] != ')' || ch == '{' && s[i] != '}' 
                || ch == '[' && s[i] != ']')return false;
                st.pop();
            }
            else return false;
        }
        
    }
    return !st.empty() ? false:true;
}