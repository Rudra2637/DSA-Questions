#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        int n = nums.size()-1;
        vector<int>temp;
        temp.push_back(nums[n]);
        int j = n;
      

        for(int i=n-1;i >= 0;i--){

            if(temp.size() == 3){
                ans.push_back(temp);
                temp.clear();
                temp.push_back(nums[i]);
                j = i;
                if(i > 0)i--;
            }
            if(nums[j] - nums[i] <= k)temp.push_back(nums[i]);
            else return {};
            
        }
        ans.push_back(temp);
        
        return ans;
    }
};

    // sort(nums.begin(),nums.end());
    //         vector<vector<int>> ans;
    //         for(int i=0;i<nums.size();i+=3){

    //             if(nums[i+2]-nums[i]<=k){
    //                 ans.push_back({nums[i],nums[i+1],nums[i+2]});
    //             }
    //             else
    //             {
    //                 return {};
    //             }
    //         }
    //         return ans;
