#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int E = 0;
        int W = 0;
        int S = 0;
        int N = 0;
        int maxi = 0;

        for(int i=0;i<s.size();i++){
            if(s[i] == 'E')E++;
            else if(s[i] == 'W')W++;
            else if(s[i] == 'N')N++;
            else S++;
            
            int mD = abs(E-W)+abs(N-S);
            int tS = i+1;

            int wasted = tS - mD;
            int extra = 0;

            if(wasted != 0) extra = min(2*k,wasted);
               
            
            int finalD = mD + extra;

            maxi = max(maxi,finalD);
        }
        return maxi;
    }
};
