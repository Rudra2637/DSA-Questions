#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool vowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')  return true;
        
        return false;
    }

    string sortVowels(string s) {
        vector<int>temp;
        for(int i=0;i<s.size();i++){
            if(vowel(s[i]))temp.push_back(s[i]);
        }
        sort(temp.begin(),temp.end());
        int j=0;
        for(int i =0;i<s.size();i++){
            if(vowel(s[i])){
                s[i] = char(temp[j]);
                j++;
            }
        }
        return s;
    }
};


// for(int i=0;i<s.size();i++){
//             if(vowel(s[i])){
//                 int asciiValue = s[i];
//                 int j=i;
//                 while(j < s.size()){
//                     if(vowel(s[j])){
//                         int val = s[j];
//                         if(val < asciiValue){
//                             swap(s[j],s[i]);
//                             asciiValue = val;
//                         }
//                     }
//                     j++;
//                 }
//             }
//         }