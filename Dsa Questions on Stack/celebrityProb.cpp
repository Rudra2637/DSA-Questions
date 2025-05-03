#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        
        int i=0;
        int j=1;
        
        while(i<mat.size() && j<mat.size()){
            if(mat[i][j] == 1 && mat[j][i] == 0){
                i=j;
                j++;
                
            }
            else if(mat[i][j] == 0 && mat[j][i] == 1){
                j++;
               
            }
            else{
                i++;
                j++;
            }
        }
        
        for(int k = 0;k<mat.size();k++){
            if(mat[i][k] == 1)return -1;
        }
        int cntZero = 0;
        for(int k = 0;k<mat.size();k++){
            if(mat[k][i] == 0)cntZero++;
        }
        if(cntZero != 1)return -1;
        
        return i;
        // stack<int>s;
        // int ind = -1;
        // for(int i=0;i<mat.size();i++){
        //   int cnt = 0;
        //     for(int j=0;j<mat.size();j++){
        //         if(i == j)continue;
                
        //         if(ind != -1 && j ==ind && mat[j][i] == 1)ind = -1;
        //         if(mat[j][i] == 1){
        //             cnt++;
        //             s.push(j);
        //         }
        //     }
        //     if(cnt == mat.size()-1){
        //         ind = i;
        //         while(!s.empty()){
        //             if(s.top() == ind){
        //                 ind=-1;
        //                 break;
        //             }s.pop();
        //         }
        //     }
        // }
                 
        
    }
};