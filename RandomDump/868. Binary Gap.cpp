#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int maxi = 0;
        vector<int>tempArr;

        for(int i=0;i <= 31;i++){
            bool temp = (n & 1<<i);
            if(temp)tempArr.push_back(i);
        }
        
        for(int i =1;i<tempArr.size();i++){
            maxi = max(abs(tempArr[i-1] - tempArr[i]),maxi);
        }
        return maxi;
    }
};