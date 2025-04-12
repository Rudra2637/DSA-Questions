#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
      int data;
      Node* left;
      Node* right;
  
      // Constructor to initialize a new node
      Node(int val) {
          data = val;
          left = NULL;
          right = NULL;
      }
  };

  void solve(Node* root,int k,vector<int>&path,int &cnt){
    if(root == NULL)return ;
    
    path.push_back(root->data);
    
    solve(root->left,k,path,cnt);
    solve(root->right,k,path,cnt);
    
    int sum = 0;
    int s = path.size();
    for(int i=s-1;i>=0;i--){
        sum += path[i];
        if(sum == k)cnt++;
    }
    path.pop_back();
    
}


int sumK(Node *root, int k) {
    // code here
    int cnt = 0;
    
    vector<int>path;
    
    solve(root,k,path,cnt);
    
    
    return cnt;
}