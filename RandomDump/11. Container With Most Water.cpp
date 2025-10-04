#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans=0;
        while(i<j){
            int length=0;
            int width=0;
            int area=0;
            if(height[i]<=height[j]){
                length=height[i];
                width=j-i;
                area=length*width;
                if(ans<area){
                    ans=area;
                }
                i++;
            }
            else{
                length=height[j];
                width=j-i;
                area=length*width;
                if(ans<area){
                    ans=area;
                }
                
                j--;
            }
            

        }
        return ans;
        
    }
};