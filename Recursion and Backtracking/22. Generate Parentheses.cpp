#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string check){
        int cnt = 0;
        for(auto it:check){
            if(it == '(')cnt++;
            else{
                cnt--;
                if(cnt<0){
                    return false;
                }
            } 
        }
        return cnt == 0 ;
    }
    void solve(string temp,vector<string>&ans,int n){
        if(temp.size() == n*2){
            if(isValid(temp)){
                ans.push_back(temp);
            }
            return ;
        }

        temp.push_back('(');
        solve(temp,ans,n);
        temp.pop_back();
        temp.push_back(')');
        solve(temp,ans,n);
        temp.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string>ans;
        solve(temp,ans,n);
        return ans;
    }
};




// class Solution {
// public:
// bool isvalid(string &temp){
//     int cnt=0;
//     for(int i=0;i<temp.size();i++){
//         if(temp[i]=='('){
//             cnt++;
//         }
//         else{
//             cnt--;
//             if(cnt<0){
//                 return false;
//             }
//         }
//     }
    
//     return cnt==0;
// }
// void solve(int n,string temp,vector<string>&ans){
//     if(temp.size()==n*2){
//         if(isvalid(temp)){
//             ans.push_back(temp);
//         }
//         return ;
//     }
//     temp.push_back('(');
//     solve(n,temp,ans);
//     temp.pop_back();
//     temp.push_back(')');
//     solve(n,temp,ans);
//     temp.pop_back();
    
// }
//     vector<string> generateParenthesis(int n) {
//         string temp="";
//         vector<string>ans;
//         solve(n,temp,ans);
        
//         return ans;
//     }
// };