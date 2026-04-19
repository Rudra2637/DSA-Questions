#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        unordered_map<int,vector<int>>m;
        int mini = INT_MAX;

        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }

        for (auto it : m) {
            if(it.second.size() >= 3){
                // cout << it.first << " -> ";
                
                int s = it.second.size();
                for (int i=s-1;i>=2;i--) {
                    int temp = 0;
                    int s1 = abs(it.second[i] - it.second[i-1]);
                    int s2 = abs(it.second[i-1] - it.second[i-2]);
                    int s3 = abs(it.second[i] - it.second[i-2]);
                    
                    temp += s1+s2+s3;
                    mini = min(temp,mini);
                }
                // cout << endl;
            }
        }
        return mini == INT_MAX ? -1:mini;
    }
};