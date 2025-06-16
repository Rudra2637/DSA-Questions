#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // int mini = *min_element(nums.begin(),nums.end());
        // int n = nums.size()-1;
        
        // if(mini == nums[n])return -1;
        
        // int maxi = 0;
        // for(int i=0;i<nums.size();i++){
        //     if(i == 0)while(nums[i] != mini)i++;
        //     else maxi = max(maxi,nums[i] - mini);
                
        // }
        int i = 0;
        int j = 1;
        int maxi = -1;
        while(i<nums.size() && j<nums.size()){
            if(nums[i] > nums[j]){
                i = j ;
                j++;
            }
            
            else if(nums[i] < nums[j]){
                maxi = max(maxi,nums[j] - nums[i]);
                j++;
            }
            else j++; 
            
        }
        // int maxi = -1;
        // int increment = nums[0];
        // for(int i=1;i<nums.size();i++){
        //     if(increment > nums[i]){
        //         increment = nums[i];
        //     }
        //     maxi = max(maxi,nums[i] - increment);
        //     if(maxi == 0)maxi = -1;
        // }
        return maxi;
    }
};
