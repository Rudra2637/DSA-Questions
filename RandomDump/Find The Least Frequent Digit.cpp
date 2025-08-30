#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int,int>m;

        while(n != 0){
            int num = n % 10;
            m[num] ++;
            n = n / 10;
        }
        int mini = INT_MAX;
        int num = 0;
        for(auto it:m){
            if(mini > it.second){
                mini = it.second;
                num = it.first;
            }
            
        }
        return num;
    }
};