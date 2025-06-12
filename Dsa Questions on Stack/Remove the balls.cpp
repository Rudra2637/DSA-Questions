#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<int>s1;
        // stack<int>s2;
        // int cnt = 0;
        
        // for(auto it:color)s1.push(it);
        
        // for(auto it:radius)s2.push(it);
        
        
        for(int i=0;i<color.size();i++){
            
            if(!s1.empty() && color[s1.top()] == color[i] && radius[i] == radius[s1.top()])
                s1.pop();
                
            else s1.push(i);
            
            
        }
        
        
        
        return s1.size();
    }
};