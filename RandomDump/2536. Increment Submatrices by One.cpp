#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n, vector<int>(n, 0));
        for (auto &q : queries) {
            for(int i = q[0];i <= q[2];i++){
                ans[i][q[1]]++;
                if(q[3]+1 < n){
                    ans[i][q[3]+1] -=1;
                }
            }
        }

        for(int i=0;i<ans.size();i++){
            int sum = 0;
            for(int j=0;j<ans.size();j++){
                sum += ans[i][j];
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};