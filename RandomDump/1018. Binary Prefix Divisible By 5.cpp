#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int num = 0;
        vector<bool>ans;
        for(int i=0;i<nums.size();i++){
            num = (num << 1 | nums[i]) % 5;
            if(num % 5 == 0)ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};