#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        
        int r = matrix.size();
        int c = matrix[0].size();

        for(int i=0;i<r;i++) for(int j = 0;j<c;j++)pq.push(matrix[i][j]);
        
        while(pq.size() != k)pq.pop();
        
        return pq.top();
    }
};