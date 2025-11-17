#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i=0;
        int j=1;

        while(i < nums.size() && j < nums.size()){
            while(i < nums.size() && nums[i] != 1)i++;
            j = i+1;
            while(j < nums.size() && nums[j] != 1)j++;
            if(j >= nums.size())break;
            if(i >= nums.size() -1)break;
            if(j - i <= k)return false;
            i++;
            j++;
        }

        return true;
    }
};