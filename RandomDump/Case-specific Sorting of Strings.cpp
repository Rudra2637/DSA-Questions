#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string temp = s;
        sort(s.begin(),s.end());
        string upper = "";
        string lower = "";
        
        for(int i=0;i<s.size();i++){
            if(islower(s[i]))lower += s[i];
            else upper += s[i];
        }
        
        int l = 0;
        int u = 0;
        for(int i=0;i<temp.size();i++){
            if(isupper(temp[i])){
                s[i] = upper[l];
                l++;
            }
            else{
                s[i] = lower[u];
                u++;
            }
        }
        
        return s;
    }
};

// string caseSort(string& s) {
//         string temp = s;
//         sort(temp.begin(),temp.end());
//         int j = 0;
//         int i = 0;
//         for(int k = 0; k < temp.size(); k++){
//             if(islower(temp[k])){
//                 i = k;
//                 break;
//             }
//         }
//         int k = 0;
//         while(k < s.size()){
//             if(isupper(s[k])){
//                 s[k] = temp[j];
//                 j++;
//             }
//             else{
//                 s[k] = temp[i];
//                 i++;
//             }
//             k++;
//         }
//         return s;
//     }