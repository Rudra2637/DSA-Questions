#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
    };
    
    Node* newNode(int val) {
        return new Node(val);
    }


class Solution {
    public:
      
      // pair<int,int>diameterFast(Node* root){
      //     if(root == NULL){
      //         pair<int,int>p = make_pair(0,0);
      //         return p;
      //     }
      //     pair<int,int>left = diameterFast(root->left);
      //     pair<int,int>right = diameterFast(root->right);
      //     int op1 = left.first;
      //     int op2 = right.first;
      //     int op3 = left.second + right.second + 1;
      //     pair<int,int>ans;
      //     ans.first = max(op1,max(op2,op3));
      //     ans.second = max(left.second,right.second)+1;
      //     return ans;
          
      // }
      int solve(Node* root,int &result){
          if(root == NULL)return 0;
          
          int l = solve(root->left,result);
          int r = solve(root->right,result);
          
          result = max(result,l+r);
          
          return max(l,r)+1;
      }
      
    
      int diameter(Node* root) {
          // Your code here
          if(root == NULL)return 0;
          int result = INT_MIN;
          solve(root,result);
          return result;
          
      }
  };