#include<bits/stdc++.h>
using namespace std;

class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

TreeNode* search(TreeNode* root,int key,pair<int,int>&p){
    if(root == NULL)return NULL;

    if(root->data == key)return root;

    if(root->data < key){
        p.first = root->data;
        return search(root->right, key, p);
    }

    if(root->data > key){
        p.second = root->data;
        return search(root->left, key, p);
    }

    return root;
}


pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    pair<int,int>p;
    p={-1,-1};
    TreeNode* temp = search(root,key,p);
    if(!temp)return p;
    

    TreeNode* right = temp->right;
    while(right){
        p.second = right->data;
        right = right->right;
    }
    
    TreeNode* left = temp->left;
    while(left){
        p.first = left->data;
        left = left->left;
    }
    
    
    
    return p;

}