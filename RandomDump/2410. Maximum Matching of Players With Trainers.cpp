#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));

        int i=0;
        int j=0;
        int s1 = players.size();
        int s2 = trainers.size();
        int cnt = 0;

        while(i<s1 && j<s2){
            if(players[i] <= trainers[j]){
                cnt++;
                i++;
            }
            j++;
        }

        return cnt;
    }
};
