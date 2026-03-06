#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s[0] == '0')return false;

        for(int i = 1;i<s.size()-1;i++){
            if(s[i] == '0' && s[i+1] == '1')return false;
        }
        return true;
    }
};