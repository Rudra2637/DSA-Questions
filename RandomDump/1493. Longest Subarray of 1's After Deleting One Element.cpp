#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        bool check = false;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] == 0){
                int cnt = 0;
                int l = i-1;
                int r = i+1;
                
                while(l >= 0 && nums[l] == 1){
                    l--;
                    cnt++;
                }
                while(r < nums.size() && nums[r] == 1){
                    r++;
                    cnt++;
                }
                ans = max(cnt,ans);
                check = true;
            }
        }
        return check == true ? ans:nums.size()-1;
    }
};