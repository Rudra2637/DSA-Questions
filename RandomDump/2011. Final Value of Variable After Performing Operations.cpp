#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;

        for(int i=0;i<operations.size();i++){
            string temp = operations[i];
            if(temp[0] == '-' || temp[1] == '-') val--;
            
            else val++;
        }
        return val;
    }
};