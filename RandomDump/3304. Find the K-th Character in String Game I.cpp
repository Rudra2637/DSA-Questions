#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        
        string s ="ab";
         
        while(s.size() <= k){
            string temp="";
            for(int i=0;i<s.size();i++){
                if(s[i] == 'z')temp += 'a';
                else {
                    char firstCh = static_cast<char>(s[i]+1);
                    temp += firstCh;
                }
            }
            s += temp;
        }
       
        return s[k-1];
    }
};
