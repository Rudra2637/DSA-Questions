#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int l = 0;
        int minLen = INT_MAX;
        long long sum = 0;

        for(int i = 0;i < nums.size();i++){
            if(++mp[nums[i]] == 1){
                sum += nums[i];
            }

            while(sum >= k){
                minLen = min(minLen,i-l + 1);
                if(--mp[nums[l]] == 0){
                    sum -= nums[l];
                }
                l++;
            }
        }

        return minLen == INT_MAX ? -1:minLen;
    }
};