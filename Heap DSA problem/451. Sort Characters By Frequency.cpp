#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        priority_queue<pair<int,char>>pq;

        for(int i=0;i<s.size();i++) m[s[i]]++;
        string ans = "";
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            while(temp.first != 0){
                ans.push_back(temp.second);
                temp.first--;
            }
        }
        
        return ans;
    }
};
