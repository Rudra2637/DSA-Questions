#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        char maxDigit = '0';
        for (char digit : n) {
            if (digit > maxDigit) {
                maxDigit = digit;
            }
        }
        return maxDigit - '0'; 
    }
};