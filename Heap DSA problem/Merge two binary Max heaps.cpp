#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // void buildHeap(vector<int>&arr,int val){
        
    //     arr.push_back(val);
    //     int s = arr.size();
        
    //     int i = s-1;
        
    //     while(i>1){
    //         int parent = i/2;
            
    //         if(arr[i] > arr[parent])swap(arr[parent],arr[i]);
            
    //         i = i/2;
    //     }
        
    // }
    
    void buildHeap(vector<int>&arr,int val){
        
        arr.push_back(val);
        int s = arr.size();
        
        int i = s-1;
        
        while(i>0){
            int parent = (i - 1) / 2;
            
            if(arr[i] > arr[parent])swap(arr[i],arr[parent]);
            
            i = (i - 1) / 2;
        }
        
    }
  
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        
        // int s = n;
        // for(int i=0;i<m;i++){
        //     a.push_back(b[i]);
        // }
        // b.clear();
        // b.push_back(1);
        
        
        // for(int i =0;i<a.size();i++){
        //     buildHeap(b,a[i]);
        // }
        
        // b.erase(b.begin());
        
        int s = a.size();
        for(int i =0;i<a.size();i++){
            buildHeap(b,a[i]);
        }
        // for(auto it:b)cout<<it<<" ";
        
        return b;
    }
    
};
