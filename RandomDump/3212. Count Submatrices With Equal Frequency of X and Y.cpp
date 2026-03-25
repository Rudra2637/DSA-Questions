#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int cnt = 0;
        vector<vector<pair<int, int>>> p(r, vector<pair<int, int>>(c)); 
        for(int i=0;i<r;i++){
            int cntX = 0;
            int cntY = 0;
            for(int j=0;j<c;j++){
                if(grid[i][j] == 'X')p[i][j].first++;
                else if(grid[i][j] == 'Y')p[i][j].second++;

                if(i-1 >= 0){
                    p[i][j].first += p[i-1][j].first;
                    p[i][j].second += p[i-1][j].second;
                }
                if(j-1 >= 0){
                    p[i][j].first += p[i][j-1].first;
                    p[i][j].second += p[i][j-1].second;
                }
                if(i-1 >= 0 && j-1 >= 0){
                    p[i][j].first -= p[i-1][j-1].first;
                    p[i][j].second -= p[i-1][j-1].second;
                }
                if(p[i][j].first == p[i][j].second && p[i][j].first != 0)cnt++;
            }
        }
        return cnt;
    }
};