#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        k=k%n;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(i % 2 == 0) matrix[i][(j+n-k) %  n] = mat[i][j];
                
                else matrix[i][(j+k) %  n] = mat[i][j];
            }
        }
        
        return matrix == mat;
    }
};