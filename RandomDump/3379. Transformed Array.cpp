#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n,0);
        for(int i = 0;i < nums.size();i++){
            int pos ;
            int k ;
            if(nums[i] < 0){
                k = abs(nums[i]);
                pos = (i - (k % n) + n) % n;
                result[i] = nums[pos];
            }
            else if(nums[i] > 0){
                k = abs(nums[i]);
                pos = (i + k) % n;
                result[i] = nums[pos];
            }
            else {
                result[i] = nums[i];
            }
        }
        return result;
    }
};