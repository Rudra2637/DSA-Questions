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

  void solve(Node* root,unordered_map<int,int>&m,int lel,int sum){
    if(root == NULL)return ;
    
    if(root->left == NULL && root->right == NULL){
        
        sum += root->data;
        lel++;
        if(m.count(lel)){
            int n = m[lel];
            if(sum > n)m[lel] = sum; 
        }
        else m[lel] = sum;
        return ;
    }
    
    sum += root->data;
    lel ++;
    
    solve(root->left,m,lel,sum);
    solve(root->right,m,lel,sum);
    
    
}

int sumOfLongRootToLeafPath(Node *root) {
    unordered_map<int,int>m;
    solve(root,m,0,0);
    int ans = 0;
    int lel = 0;
    for(auto it:m){
        if(it.first > lel){
            ans = it.second;
            lel = it.first;
        }
    } 
    
    for(auto it:m)cout<<it.first<<" "<<it.second<<endl;
    
    return ans;
}