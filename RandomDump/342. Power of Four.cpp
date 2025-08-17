#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int n) {
        if (n == 1) return true;   
        if (n <= 0 || n % 4 != 0) return false;
        return solve(n / 4);       
    }

    bool isPowerOfFour(int n) {
        return solve(n);
    }
};
