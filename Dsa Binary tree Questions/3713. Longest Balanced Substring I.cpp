#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool checkBalance(vector<int>freq){
        int temp = 0;
        for(int i=0;i<freq.size();i++){
            if(freq[i] == 0)continue;
            else if(temp == 0){
                temp = freq[i];
            }
            else if(freq[i] != temp)return false;
        }
        return true;
    }

    int longestBalanced(string s) {
        int maxi = 0;
        
        for(int i=0;i<s.size();i++){
            vector<int>temp(26,0);
            for(int j=i;j<s.size();j++){
                temp[s[j] - 'a']++;
                if(checkBalance(temp)){
                    maxi = max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};