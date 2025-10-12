#include<bits/stdc++.h>
using namespace std;

int solveRecursion(vector<int> &nums,int index,vector<int>&dp){
    if(index >= nums.size()){
        return 0;
    }

    if(dp[index] != -1)return dp[index];

    int include = solveRecursion(nums,index+2,dp) + nums[index];
    int exclude = solveRecursion(nums,index+1,dp) + 0;

    return dp[index] = max(include,exclude);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    // Recursion + Memoisation
    // int n = nums.size();
    // vector<int>dp(n,-1);
    // return solveRecursion(nums,0,dp);
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
    
}