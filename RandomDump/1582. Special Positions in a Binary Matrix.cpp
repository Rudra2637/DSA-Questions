#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool checkRow(vector<vector<int>>&mat,int c){
        bool firstTime = false;
        for(int i=0;i<mat.size();i++){
            if(mat[i][c] == 1 && firstTime == false) firstTime = true;
            
            else if(mat[i][c] == 1 && firstTime == true)return false;
        }
        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        for(int i=0;i<mat.size();i++){
            int sum = 0;
            int col = 0;
            for(int j=0;j<mat[0].size();j++){
                sum += mat[i][j];
                if(mat[i][j] == 1)col = j;
            }
            if(sum == 1) if(checkRow(mat,col))cnt++;
            
        }
        return cnt;
    }
};