#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool checkOne = false;
        bool checkZero = false;
        while(n != 0){
            if(n  & 1){
                if(checkOne)return false;
                checkOne = true;
                checkZero = false;
            }
            else {
                if(checkZero)return false;
                checkZero = true;
                checkOne = false;
            }
            n = n>>1;
        }
        return true;
    }
};