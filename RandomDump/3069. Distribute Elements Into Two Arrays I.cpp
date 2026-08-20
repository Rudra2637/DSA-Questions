#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int s = nums.size();
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int j = 0;
        int k = 0;

        vector<int>ans;
        for(int i=2;i<nums.size();i++){
            if(arr1[j] < arr2[k]){
                arr2.push_back(nums[i]);
                k++;
            }
            else{
                arr1.push_back(nums[i]);
                j++;
            } 
        }

        j=0;
        while(j < arr1.size()){
            ans.push_back(arr1[j]);
            j++;
        }
        j=0;
        while(j < arr2.size()){
            ans.push_back(arr2[j]);
            j++;
        }
        
        return ans;
    }
};

// Arr1 = 5,3
// Arr2 = 4,8

// [5,3,0,0]

// 5,4,3,8
// Arr = 5,3,4,8