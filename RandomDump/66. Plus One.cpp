#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int s = digits.size();
        int carry = 0;
        if(digits[s-1] != 9){
            digits[s-1]++;
            return digits;
        }
        else{
            digits[s-1] = 0;
            carry++;
        }

        
        for(int i = s-2;i >= 0;i --){
            if(carry >= 1){
                if(digits[i] == 9){
                    digits[i] = 0;
                    carry++;
                }
                else digits[i]++;
                carry--;
            }
            // else if(i > 0 && digits[i] == 9){
            //     digits[i] = 0;
            //     carry++;
            // }
        }

        if(digits[0] == 0){
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};



// if(s == 1 && digits[0] == 9){
//             digits[0] = 1;
//             digits.push_back(0);
//             return digits;
//         }