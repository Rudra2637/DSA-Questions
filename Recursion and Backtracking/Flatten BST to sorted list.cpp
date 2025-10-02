#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

/* Node of the binary search tree*/
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    
    // void solve(Node* root,Node* &temp){
    //     if(root == NULL)return ;
        
    //     solve(root->left,temp);
    //     temp->left = NULL;
    //     temp->right = root ;
    //     temp = temp->right;
    //     solve(root->right,temp);
    //     temp->left = NULL;
        
    // }
    
    
  
    Node *flattenBST(Node *root) {
        // code here
        // Node *temp = new Node(-1);
        // Node *ans = temp;
        // solve(root,temp);
        
        // return ans->right;
        if(root == NULL)return root;
        
        
        Node* leftPart = flattenBST(root->left);
        root->left = NULL;
        root->right = flattenBST(root->right);
        
        if(leftPart){
            Node* temp = leftPart;
            while(temp && temp->right){
                temp = temp->right;
            }
            temp->right = root;
        }
        else{
            leftPart = root;
        }
        
        return leftPart;    
        
    }
};