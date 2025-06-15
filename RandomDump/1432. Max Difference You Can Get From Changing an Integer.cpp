#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string a = to_string(num);
        string b = to_string(num);

        int x;
        int j=0;
        while(j<a.size() && a[j] == '9') j++;
        
        x = a[j];
        
        int y ;
        j=0;
        while(j<a.size() && (a[j] == '1' || a[j] == '0')) j++;
        
        y = a[j];
        bool check = false;
        if(j == 0)check = true;
        
        
        for(int i=0;i<a.size();i++){
            if(a[i] == x)a[i] = '9';
            if(check && b[i] == y)b[i] = '1';
            else if(b[i] == y)b[i] = '0';
        }
        
        return stoi(a) - stoi(b);

    }
};
