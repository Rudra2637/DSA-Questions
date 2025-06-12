#inlcude<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int i=0;
        int j=1;
        int s = nums.size()-1;
        int maxi = INT_MIN;

        while(j >= 0 && i < nums.size()){
            

            int diff = abs(nums[i] - nums[j]);
            maxi = max(maxi,diff);

            if(j == s)j = 0;
            else j++;

            i++;

        }
        return maxi;
        
    }
};