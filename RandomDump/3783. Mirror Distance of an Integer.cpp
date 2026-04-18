#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int reverse(int num){
        int temp = 0;
        int i = 0;
        while(num != 0){
            int digit = num % 10;
            temp=(temp*10)+digit;
            num = num / 10;
        }

        return temp;
    }

    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};