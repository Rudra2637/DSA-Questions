#include<bits/stdc++.h>
using namespace std;

queue<int> reverseQueue(queue<int> &q) {
        // code here.
        stack<int>s;
        while(!q.empty()){
            int a = q.front();
            q.pop();
            s.push(a);
        }
        
        while(!s.empty()){
            int a = s.top();
            s.pop();
            q.push(a);
        }
        
        
        return q;
    }