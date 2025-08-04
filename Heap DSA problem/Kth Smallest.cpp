#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    
    
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>max_heap(arr.begin(),arr.end());
        
        
        while(max_heap.size() != k) max_heap.pop();
        
        return max_heap.top();
        
    }
};
