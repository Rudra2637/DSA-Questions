#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveForward(vector<int>nums,int i,vector<int>&dp){
        if(i >= nums.size()-1)  return 0;
        
        if(dp[i] != -1)return dp[i];

        int include = solveForward(nums,i+2,dp) + nums[i];
        int exclude = solveForward(nums,i+1,dp) + 0;

        return dp[i] = max(include,exclude);
    }
    int solveBackward(vector<int>nums,int i,vector<int>&dp){
        if(i <= 0)  return 0;
        
        if(dp[i] != -1)return dp[i];

        int include = solveBackward(nums,i-2,dp) + nums[i];
        int exclude = solveBackward(nums,i-1,dp) + 0;

        return dp[i] = max(include,exclude);
    }
    

    int rob(vector<int>& nums) {
        int s = nums.size();
        if(s == 1)return nums[0];
        
        vector<int>dp(s,-1);
        int forward = solveForward(nums,0,dp);
        fill(dp.begin(), dp.end(), -1);
        
        int backward = solveBackward(nums,s-1,dp);
        return max(forward,backward);
    }
};