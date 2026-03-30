#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2)return true;
        for(int i=0;i<s1.size();i++){
            if(s1[i] == s2[i])continue;
            else {
                for(int j=i;j<s2.size();j++){
                    if(s2[j] == s1[i]){
                        if(j-i == 2)swap(s1[i],s1[j]);
                        if(s1 == s2)return true;
                    }
                }
            }
        }
        return false;
    }
};
// abcd cdab 
// 0123 0123