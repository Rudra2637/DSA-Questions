#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
    
        for(int i=0;i<nums.size();i++) sum += nums[i];
        if(sum % 3 == 0)return sum;
        
        int r1_1 = INT_MAX, r1_2 = INT_MAX;   
        int r2_1 = INT_MAX, r2_2 = INT_MAX;

        for(int x : nums) {
            if(x % 3 == 1) {
                if(x < r1_1) { r1_2 = r1_1; r1_1 = x; }
                else if(x < r1_2) r1_2 = x;
            }
            else if(x % 3 == 2) {
                if(x < r2_1) { r2_2 = r2_1; r2_1 = x; }
                else if(x < r2_2) r2_2 = x;
            }
        }

        int r = sum % 3;
        int ans = 0;

        if(r == 1) {
            int remove1 = (r1_1 == INT_MAX ? 0 : sum - r1_1);
            int remove2 = (r2_2 == INT_MAX ? 0 : sum - (r2_1 + r2_2));
            ans = max(remove1, remove2);
        }
        else { 
            int remove1 = (r2_1 == INT_MAX ? 0 : sum - r2_1);
            int remove2 = (r1_2 == INT_MAX ? 0 : sum - (r1_1 + r1_2));
            ans = max(remove1, remove2);
        }

        return ans;
    }
};