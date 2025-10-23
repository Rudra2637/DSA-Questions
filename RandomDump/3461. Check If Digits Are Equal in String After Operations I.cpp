#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() != 2){
            string temp = "";
            for(int i = 0;i<s.size()-1;i++){
                int num1 = s[i] - '0';
                int num2 = s[i+1] - '0';
                int solve = (num1 + num2) % 10;
                char a = solve + '0';
                temp += a;  
            }
            s = temp;
        }
        return s[0] == s[1];
    }
};