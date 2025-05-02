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


Node* solve(Node* root,int &k,int node){
    if(root == NULL)return NULL ;
    
    
    if(root->data == node){
      
        return root;
    }
    
    Node* left = solve(root->left,k,node);
    Node* right = solve(root->right,k,node);
    
    if(left && !right){
        k -= 1;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return left;
    }
    else if(right && !left){
        k -= 1;
       
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return right;
    }
    else return NULL;
    
}
int kthAncestor(Node *root, int k, int node) {
    // Code here
    Node* ans = solve(root,k,node);
    // cout<<k<<endl;
    if(ans == NULL || ans->data == node)return -1;
    return ans->data;
    
}