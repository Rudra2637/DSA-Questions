#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPossible(vector<int> &arr, int k, int m) {
        int sum = 0;
        int studCnt = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (sum + arr[i] > m) {
                studCnt++;
                sum = arr[i];
            } else {
                sum += arr[i];
            }
        }
        return studCnt <= k;
    }

    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1; 
        int s = *max_element(arr.begin(), arr.end());  
        int e = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;

        while (s <= e) {
            int m = s + (e - s) / 2;

            if (isPossible(arr, k, m)) {
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return ans;
    }
};