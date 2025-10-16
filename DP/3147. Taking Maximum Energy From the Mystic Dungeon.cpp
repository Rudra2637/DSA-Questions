#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int> &energy,int k,int index,vector<int>&dp){
        if(index >= energy.size()){
            return 0;
        }
        if(dp[index] != -1)return dp[index];

        return dp[index] = energy[index] + solve(energy,k,index+k,dp);
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        vector<int>dp(energy.size(),-1);
        for(int i=0;i<energy.size();i++){
            ans = max(ans,solve(energy,k,i,dp));
        }
        return ans;
    }
};