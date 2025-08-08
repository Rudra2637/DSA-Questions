#include<bits/stdc++.h>
using namespace std;

struct ComparePairFrequency{
    bool operator()(const pair<int,int> &a,const pair<int, int>& b){
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(auto it:nums)mp[it]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairFrequency> min_heap;

        for(auto it:mp){
            min_heap.push({it.second,it.first});
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
        vector<int>ans;
        while(!min_heap.empty()){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};
