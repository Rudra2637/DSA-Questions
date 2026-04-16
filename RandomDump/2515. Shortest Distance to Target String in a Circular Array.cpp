#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int s = words.size();
        
        for(int i = 0; i < s; i++){
            int n1 = (startIndex + i) % s; 
            int n2 = (startIndex - i + s) % s; 

            if(words[n1] == target || words[n2] == target) return i; 
            
        }
        
        return -1;
    }
};