#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string &s) {
        // Code here
        unordered_map<char,int>m;
        queue<int>q;
        string temp;
        
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            
            q.push(s[i]);
            while(!q.empty()){
                if(m[q.front()] <=1){
                    temp.push_back(q.front());
                    break;
                }
                else{
                    q.pop();
                }
            }
            if(q.empty())temp.push_back('#');
        }
        
        return temp;
    }