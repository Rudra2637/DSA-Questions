#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto it:arr)m[it]++;

        int maxi = -1;
        for(auto it:m){
            if(it.first == it.second){
                if(maxi == -1)maxi = it.first;
                else maxi = max(it.first,maxi);
            }
        }
        return maxi;
        
    }
};
