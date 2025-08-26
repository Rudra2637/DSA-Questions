#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxiArea = 0;
        int maxiDiagonal = 0;

        for(int i=0;i<dimensions.size();i++){
            int l = dimensions[i][0];
            int r = dimensions[i][1];

            double sqr = sqrt((l*l)+(r*r));
            
            if(maxiArea < sqr){
                maxiArea = sqr;
                maxiDiagonal = l*r;
            }
            else if(maxiArea == sqr && maxiDiagonal < (l*r)) maxiDiagonal = l*r;
            
            
        }
        return maxiDiagonal;
    }
};