#include<bits/stdc++.h>
using namespace std;

    template <typename T>
    class TreeNode {
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
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };


void solve(TreeNode<int> *root,vector<int>&nodes){
    if(root == NULL) return ;
    

    solve(root->left,nodes);
    nodes.push_back(root->data);
    solve(root->right,nodes);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> nodes;
    solve(root,nodes);
    int n = nodes.size();
    TreeNode<int> *newRoot = new TreeNode<int>(nodes[0]);

    TreeNode<int> *curr = newRoot;
    

    for(int i=1;i<n;i++){
        curr->left = NULL;
        curr->right = new TreeNode<int>(nodes[i]);
        curr = curr->right;
    }
   
    curr->left = NULL;
    curr->right = NULL;
    

    return newRoot;
}
