//https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

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

class Solution {
    public:
    
      void LeftPart(Node* root,vector<int>&ans){
          
          if(root == NULL)return ;
          
          if(!root->left && !root->right)return ;
          
          ans.push_back(root->data);
          
          if(root->left)LeftPart(root->left,ans);
          else LeftPart(root->right,ans);
          
          return ;
          
      }
      
      void leafNode(Node* root,vector<int>&ans){
          
          if(root == NULL)return ;
          if(root->left == NULL && root->right == NULL)ans.push_back(root->data);
         
          
          leafNode(root->left,ans);
          
         
          
          leafNode(root->right,ans);
          
          
          return ;
      }
      void rightPart(Node* root,vector<int>&ans){
          
          if(root == NULL)return ;
          
          if(!root->left && !root->right)return ;
          
          if(root->right)rightPart(root->right,ans);
          else rightPart(root->left,ans);
          
          ans.push_back(root->data);
          
          return ;
      }
    
      vector<int> boundaryTraversal(Node *root) {
          // code here
          
          
          vector<int>ans;
          ans.push_back(root->data);
          
          LeftPart(root->left,ans);
          if(root->left || root->right)leafNode(root,ans);
          rightPart(root->right,ans);
          
          return ans;
          //Left part
          
      }
};