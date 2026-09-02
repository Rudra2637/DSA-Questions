#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& arr, int k) {
        int ans = -1;
        bool c1 = false;
        map<int,int>s;
        int l = arr.size()-1;
        s[arr[0]]++;
        s[arr[l]]++;

        for(int i=1;i<l;i++){
            if(s.find(arr[i]) != s.end()){
                s[arr[i]]++;
            }
        }

        for(auto it:s){
            if(it.second == 1){
                ans = it.first;
            }
        }
       
        

        if(k == 1){
            for(int i=0;i<arr.size();i++){
                s[arr[i]]++;
            }
            for(auto it:s){
                if(it.second == 1){
                    ans = max(ans,it.first);
                }
            }
        }
        if(k == arr.size()){
            for(int i=0;i<arr.size();i++){
                ans = max(ans,arr[i]);
            }
        }
        

        return ans;
    }
};

// 3,9,7,2,1,7
/*
We would check only these two things 
1. If the element at 0 repeating at the 
*/