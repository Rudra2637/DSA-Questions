#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        set<int>s;

        for(int i=0;i<fruits.size();i++){
            bool check = false;
            for(int j=0;j<baskets.size();j++){
                if(s.find(j) != s.end())continue;
                if(fruits[i] <= baskets[j]){
                    s.insert(j);
                    check = true;
                    break;
                }
            }
            if(!check)cnt++;
        }

        return cnt;
        
    }
};
