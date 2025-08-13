#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool solve(int n,long long &num){
        if(n == num)return true;
        if(num > n)return false;
        num *= 3;
        return solve(n,num);
    }
    bool isPowerOfThree(int n) {
        if(n <= 0)return false;
        if(n == 1)return true;
        long long num = 3;
        bool check = solve(n,num);
        return check;
    }
};