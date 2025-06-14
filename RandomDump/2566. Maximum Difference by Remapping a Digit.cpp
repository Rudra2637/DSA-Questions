#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string temp = to_string(num);
        char a ='z';
        for(int i=0;i<temp.size();i++){
            
            if(temp[i] != '9' && a == 'z'){
                a = temp[i];
                temp[i] = '9';
            }
            else if(temp[i] == a)temp[i] = '9';
        }
        int maxi = stoi(temp);
        temp = to_string(num);
        
        a = 'z';
       
        for(int i=0;i<temp.size();i++){

            if(temp[i] != '0' && a == 'z'){
                a = temp[i];
                temp[i] = '0';
             }
            else if(temp[i] == a)temp[i] = '0';
        }
        int mini = stoi(temp);
      
        return abs(maxi-mini);
    }
};
