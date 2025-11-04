#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        vector<int>ans;
        // priority_queue<int>pq;
        
        int j = k-1;
        int i = 0;
        
        while(j < nums.size()){
            unordered_map<int,int>mp;
            int tempSum = 0;
            priority_queue<pair<int,int>>pq;
            for(int l=i;l<=j;l++){
                mp[nums[l]]++;
            }
            // for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
            for(auto it:mp)pq.push({it.second,it.first});

            // for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
            
            int cnt = 0;
            while(!pq.empty() && cnt != x){
                
                tempSum += (pq.top().second*pq.top().first);
                // cout<<pq.top().second<<" ";
                pq.pop();
                cnt++;
            }
            // cout<<endl;
            ans.push_back(tempSum);
            mp[nums[i]]--;
            mp[nums[j]]--;
            i++;
            j++;
        }

        return ans;
    }
};