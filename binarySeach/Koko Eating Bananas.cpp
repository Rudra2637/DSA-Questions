#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool isPossible(vector<int>arr,int k,int m){
        
        // int bn = m;
        // int i=0;
        // i++;
        
        // while(m < sum && i<=k){
        //     m = bn ;
        //     m = m * i;
        //     i++;
        // }
        
        // if(m < sum)return false;
        
        // return true;
        int ti = 0;
        int i=0;
        while(i<arr.size()){
            
            arr[i] -= m;
    //      cout<<k<<" ";
            if(arr[i] <= 0)i++;
            ti ++ ;
        }
        
        //  for(int i=0;i<arr.size();i++){  another solution
        //     ti += arr[i] / m ;
        //     if(arr[i] % m != 0)ti++;
        // }
        
        // cout<<k<<endl;
        return ti > k ? false : true ;
    }
  
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int sum = 0;
        int s = 1;
        
        for(auto it:arr)sum += it;
        
        
        int ans = 0;
        int e = *max_element(begin(arr),end(arr));
        int m = s+(e-s)/2;
        
        while(s <= e){
            
            if(isPossible(arr,k,m)){
                
                ans = m;
                e = m-1;
            }
            else s = m+1;
            
            m = s+(e-s)/2;
        }
        
        return ans;
    }
};