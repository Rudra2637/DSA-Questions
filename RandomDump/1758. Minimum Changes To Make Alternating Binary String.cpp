#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        if(s[0] == '0'){
            for(int i=1;i<s.size();i++){
                if(i % 2 != 0){
                    if(s[i] != '1')cnt++;
                }
                else if(s[i] != '0'){
                    cnt++;
                }
            }
            int tempCnt = 0;
            s[0] = '1';
            tempCnt++;
            for(int i=1;i<s.size();i++){
                if(i % 2 != 0 ){
                    if(s[i] != '0')tempCnt++;
                }
                else if(s[i] != '1')tempCnt++;
            }
            cnt = min(tempCnt,cnt);
        }
        else{
            for(int i=1;i<s.size();i++){
                if(i % 2 != 0 ){
                    if(s[i] != '0')cnt++;
                }
                else if(s[i] != '1')cnt++;
            }
            int tempCnt = 0;
            s[0] = '0';
            tempCnt++;
            for(int i=1;i<s.size();i++){
                if(i % 2 != 0){
                    if(s[i] != '1')tempCnt++;
                }
                else if(s[i] != '0'){
                    tempCnt++;
                }
            }
            cnt = min(tempCnt,cnt);
        }
        return cnt;
    }
};