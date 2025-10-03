#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
        for (int c = col - 1; c >= 0; c--) {
            if (board[row][c] == 1) return false;
        }
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == 1) return false;
        }
        for (int r = row + 1, c = col - 1; r < n && c >= 0; r++, c--) {
            if (board[r][c] == 1) return false;
        }
        return true;
    }

    void solve(int n,int &cnt,vector<vector<int>>arr,int col){
        if(col == n){
            cnt++;
            return ;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,arr,n)){
                arr[row][col] = 1;
                solve(n,cnt,arr,col+1);
                arr[row][col] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        int cnt = 0;
        solve(n,cnt,arr,0);
        return cnt;
    }
};