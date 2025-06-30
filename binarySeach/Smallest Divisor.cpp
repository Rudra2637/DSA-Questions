#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool isPossible(vector<int>arr,int k,int m){
        
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i]/m;
            if(arr[i] % m != 0)sum++;
           
        } 
        
        return sum <= k ;
    }
  
  
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int s = 1;
        int e = *max_element(begin(arr),end(arr));
        int m = s+(e-s)/2;
        
        int ans ; 
        
        while(s <= e){
            
            if(isPossible(arr,k,m)){
                // cout<<m<<" ";
                ans = m;
                e = m-1;
            }
            else s = m+1;
            
            m = s+(e-s)/2;
        }
        
        return ans;
    }
};
