#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = pow(2,k);
        vector<int>arr(len,-1);
        string temp = "";
        int j = 0;
        if(s.size() < k)return false;
        while(j < k){
            temp += s[j];
            j++;
        } 
        int i=0;
        
        for(j = j-1;j<s.size();j++){
            int value = stoi(temp,nullptr,2);
            arr[value] = value;
            temp.erase(0,1);
            temp += s[j+1];
        }
        // for(auto it:arr)cout<<it<<endl;
        for(auto it:arr)if(it == -1)return false;
        
        return true;
    }
};