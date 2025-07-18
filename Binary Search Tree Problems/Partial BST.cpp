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


bool BST(BinaryTreeNode<int>* root,int mini,int maxi){
    if(root == NULL)return true;

    if(root->data >= mini && root->data <= maxi){
        bool left = BST(root->left,mini,root->data);
        bool right = BST(root->right,root->data,maxi);
        return left && right;
    }
    else return false;
}


bool validateBST(BinaryTreeNode<int> *root) {
    return BST(root,INT_MIN,INT_MAX);
}