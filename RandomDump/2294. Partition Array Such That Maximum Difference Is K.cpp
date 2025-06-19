#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int cnt = 0;
        sort(nums.begin(),nums.end());
        int j =0;
        for(int i=1;i<nums.size();i++){
            if(abs(nums[j] - nums[i]) > k){
                cnt++;
                j = i;
            }
            
        }
        return cnt+1;
    }
};
