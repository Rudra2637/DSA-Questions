#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool vowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')  return true;
        return false;
    }

    int maxFreqSum(string s) {
        unordered_map<char,int>m;

        for(int i=0;i<s.size();i++) m[s[i]]++;
        
        int maxiVO = 0;
        int maxiCON = 0;
        for(auto it:m){
            if(vowel(it.first)) maxiVO = max(maxiVO,it.second);
            
            else maxiCON = max(maxiCON,it.second);
        }
        return maxiVO + maxiCON ;
    }
};