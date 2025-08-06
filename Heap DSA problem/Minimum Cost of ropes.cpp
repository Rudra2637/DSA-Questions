#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>min_heap(begin(arr),end(arr));
        
        int totalCost = 0;
        
        while(min_heap.size() != 1){
            
            int num1 = min_heap.top();
            min_heap.pop();
            int num2 = min_heap.top();
            min_heap.pop();
            
            int sum = num1+num2;
            
            totalCost += sum;
            min_heap.push(sum);
            
        }
        
        return totalCost;
    }
};
