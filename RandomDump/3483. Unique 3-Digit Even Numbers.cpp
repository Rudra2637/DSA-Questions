#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cntEven = 0;
        int s = digits.size();
        unordered_set<int>st;

        for(int i=0;i<s;i++) {
            for(int j=0;j<s;j++){
                for(int k=0;k<s;k++){
                    if(i == j || j == k || i == k || digits[i] == 0)continue ; 
                    int temp = digits[i]*100 + digits[j]*10 + digits[k];
                    if(temp % 2 == 0 && st.find(temp) == st.end()){
                        st.insert(temp);
                        cntEven ++;
                    }
                }
            }
        }
        return cntEven ; 
    }
};