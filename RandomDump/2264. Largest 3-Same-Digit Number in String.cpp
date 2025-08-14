#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int cnt = 1;
        string ans = "";

        for(int i=0;i<num.size()-2;i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                if(ans[0] < num[i]){
                    ans.clear();
                    ans += num[i];
                    ans += num[i];
                    ans += num[i];
                }
                else if(ans == ""){
                    ans += num[i];
                    ans += num[i];
                    ans += num[i];
                }
                i = i+2;
            }
        }
        return ans;
    }
};
