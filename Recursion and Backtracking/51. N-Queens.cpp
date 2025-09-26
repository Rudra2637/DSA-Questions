#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, int n) {
        for (int c = col - 1; c >= 0; c--) {
            if (board[row][c] == 'Q') return false;
        }
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == 'Q') return false;
        }
        for (int r = row + 1, c = col - 1; r < n && c >= 0; r++, c--) {
            if (board[r][c] == 'Q') return false;
        }
        return true;
    }

    void addSolution(vector<vector<string>>& ans, vector<vector<char>>& board) {          //Yes
        vector<string> temp;
        for (int i = 0; i < board.size(); i++) {
            string row(board[i].begin(), board[i].end());
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    void solve(vector<vector<string>>& ans, vector<vector<char>>& board, int n, int col) {
        if (col == n) {
            addSolution(ans, board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(ans, board, n, col + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        solve(ans, board, n, 0);
        return ans;
    }
};
