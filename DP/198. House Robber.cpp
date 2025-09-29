#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>nums,int i,vector<int>&dp){
        if(i == nums.size() || i > nums.size()){
            return 0;
        }
        if(dp[i] != -1)return dp[i];
        int steal = nums[i] + solve(nums,i+2,dp);
        int skip = solve(nums,i+1,dp);

        return dp[i] = max(steal,skip);
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};
// int maxi = INT_MIN;
        // for(int i=0;i<=1;i++){
        //     int sum = 0;
        //     for(int j = i;j<nums.size();j++){
        //         sum += nums[j];
        //         j++;
        //     }
        //     maxi = max(sum,maxi);
        // }
        // return maxi;