#include<bits/stdc++.h>
using namespace std;
    
    template <typename T>
    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


void solve(BinaryTreeNode<int> *root,int &k,int &ans){
    if(root == NULL) return ;
    
    solve(root->left,k,ans);
    k--;
    if(k == 0){
        ans = root->data;
        return ;
    }
    solve(root->right,k,ans);
    
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int ans = -1;
   
    solve(root,k,ans);

    return ans;
}