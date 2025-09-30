#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int s = nums.size();
        
        for(int i=0;i<nums.size()-1;i++){
            for(int j = 0;j<nums.size()-(i+1);j++){
                nums[j] = (nums[j] + nums[j+1]) % 10;
            }
            
        }
        return nums[0];
    }
};