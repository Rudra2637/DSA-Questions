#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool isSafe(int r,int c,vector<vector<int>>maze,vector<vector<int>>visited){
        if(r >= 0 && r < maze.size() && c >= 0 && c < maze.size() && maze[r][c] == 1 && 
        visited[r][c] == 0){
            return true;
        }
        return false;
    }
  
    void solve(vector<vector<int>>& maze,vector<vector<int>> visited,vector<string>&ans,string temp,
    int r,int c){
        
        if(r == maze.size()-1 && c == maze.size()-1){
            ans.push_back(temp);
            return ;
        }
        
        //Down
        visited[r][c] = 1;
        if(isSafe(r+1,c,maze,visited)){
            temp.push_back('D');
            solve(maze,visited,ans,temp,r+1,c);
            temp.pop_back();
        }
        
        //Left
        if(isSafe(r,c-1,maze,visited)){
            temp.push_back('L');
            solve(maze,visited,ans,temp,r,c-1);
            temp.pop_back();
        }
        
        //Right
        if(isSafe(r,c+1,maze,visited)){
            temp.push_back('R');
            solve(maze,visited,ans,temp,r,c+1);
            temp.pop_back();
        }
        
        //Up
        if(isSafe(r-1,c,maze,visited)){
            temp.push_back('U');
            solve(maze,visited,ans,temp,r-1,c);
            temp.pop_back();
        }
        
        
        visited[r][c] = 0;
        
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        
        int n = maze.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<string>ans;
        string temp = "";
        
        solve(maze,visited,ans,temp,0,0);
        
        return ans;

    }
};