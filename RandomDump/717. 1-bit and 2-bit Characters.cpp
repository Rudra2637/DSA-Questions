#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
    
        for(int i=0;i<bits.size();i++){
            if(bits[i] == 1){ 
                i ++;
            }
            else if(bits[i] == 0 && bits.size()-1 == i)return true;
        }
        return false;
    }
};