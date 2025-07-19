#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
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

bool solve(BinaryTreeNode<int>*root,int target,set<int>&s){
    if(root == NULL)return false;

    bool left = solve(root->left,target,s);
    int num = target-root->data;
    if(s.find(num) != s.end())return true;
    s.insert(root->data);
    bool right = solve(root->right,target,s);

    return left || right;
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    set<int>s;
    return solve(root,target,s);
}
