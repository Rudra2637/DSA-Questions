#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        for(i ;i<nums.size();i++){
            int cnt = 0;
            j = i+k;
            while(j < nums.size()-1 && cnt != k-1){
                if(nums[j] >= nums[j+1])break;
                j++;
                cnt++;
            }
            if(cnt == k-1)
            {
                cnt = 0;
                int temp = i;
                while(i < nums.size()-1 && cnt != k-1){
                    if(nums[i] >= nums[i+1])break;
                    i++;
                    cnt++;
                }
                if(cnt != k-1)i = temp;
                else return true;
            }
        }
        return false;
    }
};