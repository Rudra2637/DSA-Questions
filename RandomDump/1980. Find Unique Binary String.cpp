#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int n;
    // void solve(string curr,string &ans,string temp,unordered_map<string,int>m){
    //     if(temp.size() == n){
    //         if(m.find(temp) == m.end())ans=temp;

    //         return ;
    //     }
    //     for(int i=0;i<curr.size();i++){
    //         temp.push_back(curr[i]);
    //         solve(curr,ans,temp,m);
    //         temp.pop_back();
    //     }
    //     return ;

    // }

    string findDifferentBinaryString(vector<string>& nums) {
        // string curr="01";
        // string ans="";
        // string temp="";
        // unordered_map<string,int>m;
        // for(auto it:nums)m[it]++;
        // n=nums[0].size();
        
        // solve(curr,ans,temp,m);
        // return ans;
        string ans="";
        for(int i=0;i<nums.size();i++){
            char ch = nums[i][i];
            ans += ch;
            ans.back() == '0' ? ans.back() ='1':ans.back() = '0';
        }
        return ans;
    }
};