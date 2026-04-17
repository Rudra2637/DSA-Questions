#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int cntU = 0;
        int cntL = 0;
        for(int i=0;i<moves.size();i++){
            if(moves[i] == 'U') cntU++;
            else if(moves[i] == 'R')cntL++;
            else if(moves[i] == 'D')cntU--;
            else cntL--;
            
        }
        return cntU == 0 && cntL == 0;
    }
};