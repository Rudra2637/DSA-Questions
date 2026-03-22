#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        for(int k = 1;k<=4;k++){
            for(int i=0;i<mat.size();i++){
                for(int j=i+1;j<mat[0].size();j++){
                    swap(mat[i][j],mat[j][i]);
                }
                reverse(mat[i].begin(), mat[i].end());
            }
            if(mat == target)return true;
        }
        return false;
    }
};
//0,1,2
//1