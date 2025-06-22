#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;

        for(int i=0;i<s.size();i++){
            string temp = "";
            while(temp.size() != k){
                if(i == s.size()){
                    while(temp.size() != k)temp += fill;
                    break;
                }
                temp += s[i];
                i++;            
            }
            i--;
            ans.push_back(temp);
        }

        return ans;
    }
};
