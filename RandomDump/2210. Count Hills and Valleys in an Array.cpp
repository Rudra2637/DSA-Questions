#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int j = 2;
        int k = 0;
        int cnt = 0;
        
        int i=1;

        while(i<nums.size() && j<nums.size()){
            if(nums[i] > nums[k] && nums[i] > nums[j]){
                cnt++;
                i++;
                j++;
                k++;
            }
            else if(nums[i] < nums[k] && nums[i] < nums[j]){
                cnt++;
                i++;
                j++;
                k++;
            }
            else if(nums[i] == nums[j]){
                while(j < nums.size() && nums[j] == nums[i])j++;
                if(j < nums.size() && nums[i] > nums[k] && nums[i] > nums[j])cnt++;
                    
                else if(j < nums.size() && nums[i] < nums[k] && nums[i] < nums[j])cnt++;
                i = j-1;
                k = i-1;
            }
            else {
                i++;
                j++;
                k++;
            }
        }

        return cnt;
    }
};
