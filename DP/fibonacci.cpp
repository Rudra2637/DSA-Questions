#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fibNum(int n,vector<int>dp){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(dp[n] != -1)return dp[n];

        dp[n] = fibNum(n-1,dp) + fibNum(n-2,dp);
        return dp[n];
    }

    int fib(int n) {
        // if(n==0){
        //     return 0;
        // }
        // if(n==1){
        //     return 1;
        // }
        
        // return fib(n-1)+fib(n-2);
        vector<int>dp(n+1,-1);
        return fibNum(n,dp);
    }
};