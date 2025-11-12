#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool check(vector<vector<int>>&mat,int r,int c){
        if(r >= mat.size() || c >= mat[0].size() )return true;
        
        return false;
    }
    
    // void solve(vector<vector<int>> &mat,int k,int &paths,int cost,int r,int c){
    //     if(r >= mat.size()-1 && c >= mat[0].size()-1){
    //         cost += mat[r][c];
    //         if(cost == k)paths++;
    //         return ;
    //     }
        
    //     if(cost > k){
    //         return ;
    //     }
        
        
    //     if(!check(mat,r+1,c)){
    //         cost += mat[r][c];
    //         solve(mat,k,paths,cost,r+1,c);
    //         cost -= mat[r][c];
    //     }
        
    //     if(!check(mat,r,c+1)){
    //         cost += mat[r][c];
    //         solve(mat,k,paths,cost,r,c+1);
    //         cost -= mat[r][c];
    //     }
        
        
    // }
    int solve(vector<vector<int>> &mat,int k,int cost,int r,int c,vector<vector<vector<int>>> &dp){
        if(check(mat,r,c))return 0;
        
        cost += mat[r][c];
        
        if(r >= mat.size()-1 && c >= mat[0].size()-1){
            if (cost == k) return 1;
            else return 0;
        }
        
        if(cost > k){
            return 0;
        }
        if (dp[r][c][cost] != -1) return dp[r][c][cost];

        
        int down = solve(mat,k,cost,r+1,c,dp);
        
        
        
        int right = solve(mat,k,cost,r,c+1,dp);
        
        
        return dp[r][c][cost] = down + right;
    }
    

    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        
        return solve(mat,k,0,0,0,dp);
        
    }
};