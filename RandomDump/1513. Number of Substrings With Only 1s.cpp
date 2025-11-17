#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    const long long MOD = 1e9 + 7;
    
    int numSub(string s) {
        long long cnt = 0;
        for(int i=0;i<s.size();i++){
            while(i < s.size() && s[i] != '1')i++;
            int j = i+1;
            while(j < s.size() && s[j] == '1')j++;
            j--;
            long long n = (j - i) + 1;
            if(i >= s.size() && j >= s.size())break;
            cnt =  (cnt + n * (n+1) / 2) % MOD;
            i = j;
        }
        return cnt ;
    }
};