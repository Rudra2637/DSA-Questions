#include <bits/stdc++.h> 
using namespace std;
int findMinimumCost(string str) {
  // Write your code here
  if(str.size() % 2 != 0)return -1;

  int rev=0;
  stack<char>st;
  for (int i = 0; i < str.size(); i++) {
    char ch =str[i];
    if(ch =='{')st.push(ch);
    else{
      if(st.empty()){
        rev++;
        st.push('{');
      } 
      else if (st.top() == '{') {
        st.pop();
      }
    }
  }
  int s=st.size();
  if(s!=0){
    return (s/2)+rev;
  }
  return rev;
}