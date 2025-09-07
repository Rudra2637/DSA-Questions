#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        int cnt =1;
        for(int i=0;i<n;i++){
            if(i % 2 == 0)  ans.push_back(cnt);
            else ans.push_back(-cnt+1);
            cnt++;
        }
        if(n%2!=0)ans[n-1]=0;
        return ans;
    }
};