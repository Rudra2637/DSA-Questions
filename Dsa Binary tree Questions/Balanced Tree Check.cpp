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
      
      int check(Node* root) {
          if (root == NULL) return 0;  // Base case: height of empty tree is 0
          
          int leftHeight = check(root->left);
          if (leftHeight == -1) return -1;  // Left subtree is not balanced
          
          int rightHeight = check(root->right);
          if (rightHeight == -1) return -1;  // Right subtree is not balanced
          
          if (abs(leftHeight - rightHeight) > 1) return -1;  // Current node is unbalanced
          
          return max(leftHeight, rightHeight) + 1;  // Return height if balanced
      }
    
      bool isBalanced(Node* root) {
          return check(root) != -1;  // If -1 is returned, tree is not balanced
      }
  };
  