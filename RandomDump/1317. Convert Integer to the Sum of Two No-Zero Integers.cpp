#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int num1 = n - 1;
        int num3;
        int temp = num1;
        while(num1 != 0){
            num3 = num1 % 10;
            num1 = num1 / 10;
            if(num3 == 0){
                num1 = temp;
                num1--;
                temp = num1;
            }
        }
        
        int num2 = n - temp;
        int temp1 = num2;
        int num4;
        while(num2 != 0){
            num4 = num2 % 10;
            num2 = num2 / 10;
            if(num4 == 0){
                num2 = temp1;
                num2++;
                temp--;
                temp1 = num2;
            }
        }
        return {temp,temp1};
    }
};