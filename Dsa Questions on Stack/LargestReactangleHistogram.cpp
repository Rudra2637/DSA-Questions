#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>R;
        vector<int>RT(n);
        vector<int>LT;
        R.push(n);

        for(int i=n-1;i>=0;i--){
            while(R.top() != n && heights[R.top()]>=heights[i]){
                R.pop();
            }
            RT[i]=R.top();
            R.push(i);
        }
        while(!R.empty())R.pop();
        
        R.push(-1);
        for(int i=0;i<n;i++){
            while(R.top() != -1 && heights[R.top()] >= heights[i]){
                R.pop();
            }
            LT.push_back(R.top());
            R.push(i);
        }
        int maxi = 0;
        for(int i=0;i<RT.size();i++){
            int width = RT[i] - LT[i] - 1;
            int area = heights[i] * width;
            maxi=max(area,maxi);
        }
        return maxi;
    }
};
