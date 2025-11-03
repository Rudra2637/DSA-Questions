#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minTime = 0;
        
        for(int i=0;i<colors.size();i++){
            int j = i+1;
            
            while(i < colors.size() && colors[i] == colors[j]){
                
                
                if(neededTime[i] > neededTime[j]){
                    minTime += neededTime[j];
                }
                else {
                    minTime += neededTime[i];
                    i = j;
                }
                j++;
            }
            
            i = j-1;
        }
        return minTime;
    }
};
