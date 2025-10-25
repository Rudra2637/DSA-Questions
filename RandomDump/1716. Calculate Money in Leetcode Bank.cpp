#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int money = 0;
        int temp = 1;
        int j = 1;
        int cnt = 1;
        for(int i=1;i<=n;i++){
            if(cnt == 8){
                temp ++ ;
                j = temp;
                cnt = 1;
            }
            money += j;
            j++;
            cnt++;
        }
        return money;
    }
};