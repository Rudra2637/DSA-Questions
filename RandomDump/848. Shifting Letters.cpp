#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size()-1;
        long long sum = 0;
        for(int i=n;i>=0;i--){
            sum = (sum + shifts[i]) % 26;
            shifts[i] = sum;
        }

        for(int i=0;i<s.size();i++){
            int shift = shifts[i] % 26;
            int pos = s[i] - 'a';
            pos = (pos+shift) % 26;
            s[i] = char('a' + pos);
        }
        return s;
    }
};