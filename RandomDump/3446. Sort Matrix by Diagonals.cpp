#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void fillValues(vector<vector<int>>& grid,vector<int>temp,int index){
        for(int j = index;j<=index;j++){
            int r = 0;
            int c = j+1;
            int i=0;
            while(i < temp.size() && r < grid.size() && c < grid[0].size()){
                grid[r][c] = temp[i];
                i++;
                r++;
                c++;
            }
        }
    }
    void fillValue(vector<vector<int>>& grid,vector<int>temp,int index){
        for(int j = index;j<=index;j++){
            int r = j;
            int c = 0;
            int i=0;
            while(i < temp.size() && r < grid.size() && c < grid[0].size()){
                grid[r][c] = temp[i];
                i++;
                r++;
                c++;
            }
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        for(int j=0;j<grid[0].size();j++){
            vector<int>temp;
            int r = 0;
            int c = j+1;
            while(r < grid.size() && c < grid[0].size()){
                temp.push_back(grid[r][c]);
                r++;
                c++;
            }
            sort(temp.begin(),temp.end());
            fillValues(grid,temp,j);
        }
        for(int i=0;i<grid.size();i++){
            vector<int>temp;
            int r = i;
            int c = 0;
            while(r < grid.size() && c < grid[0].size()){
                temp.push_back(grid[r][c]);
                r++;
                c++;
            }
            sort(temp.begin(),temp.end());
            reverse(temp.begin(),temp.end());
            fillValue(grid,temp,i);
        }

        return grid;
        
    }
};
