#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int s1 = g.size();
        int s2 = s.size();
        int j = 0;
        int cnt = 0;

        while(i<s1 && j<s2){
            if(g[i] <= s[j]){
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};
