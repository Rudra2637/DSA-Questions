#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num = 1;
        if(k % 2 == 0 || k % 5 == 0 || k % 10 == 0)return -1;
        string ans = "1";
        if(num % k == 0)return ans.size();

        num = ((num * 10)+1) % k;
        ans += "1";
        
        while(true){
            if(num  == 0){
                return ans.size();
            }
            num = ((num * 10)+1) % k;
            ans += "1";
        }
        
        return -1;
    }
};