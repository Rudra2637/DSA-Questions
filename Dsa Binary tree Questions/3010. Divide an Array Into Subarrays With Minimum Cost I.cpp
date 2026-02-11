#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int miniCost = nums[0];
        sort(nums.begin()+1,nums.end());
        int i = 1;
        while(i != 3){
            miniCost += nums[i];
            i++;
        }

        return miniCost;
    }
};
