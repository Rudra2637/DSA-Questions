#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        string c = "";
        
        while(i >= 0 || j >= 0){
            int sum = carry;

            if(i >= 0){
                sum += a[i] - '0';
                i--;
            }
            
            if(j >= 0){
                sum += b[j] - '0';
                j--;
            }
            c.push_back((sum % 2 == 0) ? '0':'1');
            carry = sum > 1 ? 1:0;
        }
        if(carry){
            c.push_back('1');
        }
        reverse(begin(c),end(c));
        return c;
    }
};
//   11
// //101
// //111
//    00