#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int operations = 0 ;
        int cntOnes = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1')cntOnes ++;
            
            else{
                while(i < s.size()-1 && s[i+1] == '0')i++;
                operations += cntOnes;
            }
        }
        return operations;
    }
};