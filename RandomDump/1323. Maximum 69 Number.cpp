#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string temp = to_string(num);

        for(int i=0;i<temp.size();i++){
            if(temp[i] != '9'){
                temp[i] = '9';
                break;
            }
        }
        return stoi(temp);
    }
};