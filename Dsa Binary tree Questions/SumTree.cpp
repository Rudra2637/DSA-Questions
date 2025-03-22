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
      
      int verify(Node* root,int &d){
          
          if(root == NULL){
              return 0;
          }
          
          int l = verify(root->left,d);
          d += root->data;
          
          int r = verify(root->right,d);
          
          return d;
          
      }
     
      
    
    
      bool isSumTree(Node* root) {
          // Your code here
          if(root == NULL)return true;
          if(root->left == NULL && root->right)return false;
          if(root->right == NULL && root->left)return false;
          
          bool l = isSumTree(root->left);
          
          bool r = isSumTree(root->right);
        
         
          bool check;
          if(root->left && root->right){
              int d1 = 0;
              int d2 = 0;
              check = verify(root->left,d1) + verify(root->right,d2) == root->data;
              
          }
          else check = true;
          
          
          if(l && r && check)return true;
          
          
          return false;
       //   return SumFast(root).first;
      }
      // 6 6 9 3 5 1 7 N 4
      //14 N 13 N 10 N 9 N 8 N 4
  };