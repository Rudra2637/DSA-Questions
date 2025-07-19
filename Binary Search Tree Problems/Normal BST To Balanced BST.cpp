#include<bits/stdc++.h>
using namespace std;

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };


void inorder(TreeNode<int> *root,vector<int> &arr){
    if(root == NULL)return ;

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

TreeNode<int> *inorderToBST(int s,int e,vector<int>arr){
    if(s>e) return NULL;

    int m = (s+e)/2;

    TreeNode<int> *root =new TreeNode<int> (arr[m]);
    root->left = inorderToBST(s,m-1,arr);
    root->right = inorderToBST(m+1,e,arr);

    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int>arr;
    inorder(root,arr);


    return inorderToBST(0,arr.size()-1,arr);
}
