#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int start = 0;
        int bal = 0;
        int km = 0;
        for(int i=0;i<gas.size();i++){
            bal += gas[i];
            bal -= cost[i];
            if(bal < 0){
                km += bal;
                start = i+1;
                bal = 0;
            }
        }
        if((bal + km) >= 0)return start;
        else return -1;
        
    }
};