#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        string binary = "";
        for (int i = 0; i <= 31; i++) {
            binary += ((n >> i) & 1) ? '1' : '0';
        }
        return bitset<32>(binary).to_ulong();
    }
};