#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>temp(n,0);
        
        for(int i = 0;i < shifts.size();i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];
            if(direction == 1){
                temp[start]++;
                if(end+1 < n)temp[end+1]--; 
            }
            else{
                temp[start]--;
                if(end+1 < n)temp[end+1]++;
            }
        }
        int sum = 0;
    
        for(int i =0;i < temp.size();i++){
            sum += temp[i]; 
            temp[i] = sum;
        }
        
        for (int i = 0; i < n; i++) {
            int shift = temp[i] % 26;        
            if (shift < 0) shift += 26;       
            int pos = s[i] - 'a';
            pos = (pos + shift) % 26;

            s[i] = char('a' + pos);
        }

        return s;
    }
};