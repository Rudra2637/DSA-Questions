#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool checkPrime(int number){
        if(number == 1 || number == 0)return false;
        for(int i=2;i<number;i++){
            if(number % i == 0)return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i=left;i<=right;i++){
            int temp = __builtin_popcount(i);
            if(checkPrime(temp)) cnt++;
        }
        return cnt;
    }
};