#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        
        int findWays(int n,vector<int>&ans){
            if(n == 1 || n == 0){
                return 1;
            }
            
            if(ans[n] != -1)return ans[n];
            
            int ways = findWays(n-1,ans)+findWays(n-2,ans);
            ans[n] = ways;
            
            return ways;
        }
    
    
        int numberOfWays(int n) {
            // code here
            vector<int>ans(n+1,-1);
            
            
            return findWays(n,ans);
            
        }
};