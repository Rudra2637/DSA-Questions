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
    // Function to check if two trees are identical.
    
    // void traverse(Node* root,vector<int>&arr){
    //     if(root == NULL)return ;
        
    //     traverse(root->left,arr);
    //     arr.push_back(root->data);
    //     traverse(root->right,arr);
    // }
    
    
    bool isIdentical(Node *r1, Node *r2) {
        // Your Code here
        // vector<int>arr;
        // vector<int>arr1;
        // if(r1->left != NULL && r2->left == NULL || r1->left == NULL && r2->left != NULL)return false;
        // if(r1->right != NULL && r2->right == NULL || r1->right == NULL && r2->right != NULL)return false;
        // traverse(r1,arr);
        // traverse(r2,arr1);
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i] != arr1[i])return false;
        // }
        
        // return true;
        if(r1 == NULL && r2 == NULL)return true;
        
        if(r1 != NULL && r2 == NULL)return false;
        
        if(r1 == NULL && r2 != NULL)return false;
        
        bool l = isIdentical(r1->left,r2->left);
        
        bool r = isIdentical(r1->right,r2->right);
        
        bool check = r1->data == r2->data;
        
        if(l && r && check)return true;
        
        return false;
        
        
        
    }
};
