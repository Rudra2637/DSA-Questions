#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<int,vector<int>,greater<int>>min_heap;
    int r = kArrays.size();
    
    for(int i =0;i<r;i++){
        for(int j=0;j<kArrays[i].size();j++){
            min_heap.push(kArrays[i][j]);
            // cout<<kArrays[i][j]<<" ";
        }
    }
    // cout<<min_heap.size();
    vector<int>Arr;
    while(!min_heap.empty())
    {
        Arr.push_back(min_heap.top());
        min_heap.pop();
    }
    
    return Arr;
}
