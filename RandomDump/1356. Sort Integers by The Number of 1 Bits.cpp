#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda= [&] (int &a,int &b){
            int cnt_a=__builtin_popcount(a);
            int cnt_b=__builtin_popcount(b);
            
            if(cnt_a==cnt_b){
                return a<b;
            }
            
            return cnt_a < cnt_b;            
            
        };
        sort(begin(arr),end(arr),lambda);
        return arr;
    }
};