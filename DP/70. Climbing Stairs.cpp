#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int n,vector<int>&dp){
        if(n == 0 || n == 1){
            return 1;
        }

        if(dp[n] != -1)return dp[n];

        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }

    int climbStairs(int n) {
        // if (n == 0 || n == 1) {
        //     return 1;
        // }
        // int prev = 1, curr = 1;
        // for (int i = 2; i <= n; i++) {
        //     int temp = curr;
        //     curr = prev + curr;
        //     prev = temp;
        // }
        // return curr;
        // vector<int>dp(n+1,-1);
        // return solve(n,dp);

        //Bottom Up Approach

        vector<int>dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i <= n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};