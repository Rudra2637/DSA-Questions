#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int>s;
        int cnt = 0;
        while(cnt != k){
            int num = q.front();
            s.push(num);
            q.pop();
            cnt++;
        }
        // vector<int>temp;
        // while(!q.empty()){
        //     temp.push_back(q.front());
        //     q.pop();
        // }
        
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        cnt = 0;
        while(cnt < q.size()-k){
            int num = q.front();
            q.push(num);
            q.pop();
            cnt++;
        }
        // for(auto it:temp){
        //     q.push(it);
        // }
        return q;
    }