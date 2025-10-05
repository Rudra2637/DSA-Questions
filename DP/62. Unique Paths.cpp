#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool isSafe(int x,int y,int m,int n){
//         if((x >=0 && x < m) && (y >= 0 && y < n))return true;

//         return false;
//     }
//     void solve(int x,int y,int m,int n,int &cnt){
//         if(x == m-1 && y == n-1){
//             cnt++;
//             return ;
//         }

//         if(isSafe(x+1,y,m,n)) solve(x+1,y,m,n,cnt);

//         if(isSafe(x,y+1,m,n)) solve(x,y+1,m,n,cnt);

//     }

//     int uniquePaths(int m, int n) {
        //    int cnt = 0;
//         solve(0,0,m,n,cnt);
//         return cnt;
//     }
// };
class Solution {
public:
    int solve(int x, int y, int m, int n,vector<vector<int>>&dp) {
        if (x == m - 1 && y == n - 1) {
            return 1;
        }

        if(x >= m || y >= n){
            return 0;
        }
        if(dp[x][y] != -1)return dp[x][y];

        int right = solve(x + 1, y, m, n, dp);
        int down =  solve(x, y + 1, m, n, dp);

        return dp[x][y] = down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans = solve(0, 0, m, n,dp);
        return ans;
    }
};
