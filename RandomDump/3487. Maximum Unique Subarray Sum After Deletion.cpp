#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int>m;
        int maxi = INT_MIN;
        for(auto it:nums){
            m[it]++;
            maxi = max(maxi,it);
        }
        if(maxi<=0)return maxi;

        int sum = 0;
        for(auto it:m) if(it.first > 0)sum += it.first;
        
        return sum;
    }
};
