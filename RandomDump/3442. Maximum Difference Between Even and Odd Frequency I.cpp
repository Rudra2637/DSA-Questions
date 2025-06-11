#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        
        unordered_map<char,int>m;

        for(auto it:s) m[it]++;

        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto it:m){
            if(it.second%2 == 0)mini = min(it.second,mini);
            
            else maxi = max(maxi,it.second);
        }
       
        return maxi - mini;
    }
};