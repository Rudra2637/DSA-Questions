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


TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q){
    // if(root == NULL)return NULL;

    // if(root->data == p->data || root->data == q->data)return root;

    // TreeNode *leftPart = solve(root->left,p,q);
    // TreeNode *rightPart = solve(root->right,p,q);

    // if(leftPart && rightPart)return root;
    // else if(leftPart && !rightPart)return leftPart;
    // else if(!leftPart && rightPart)return rightPart;
    
    // return NULL;
    if(root == NULL)return NULL;

    while(root){
        if(root->data > p->data && root->data > q->data){
            root = root->left;
        }
        else if(root->data < p->data && root->data < q->data){
            root = root->right;
        }
        else return root;
    }
   
}

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    return solve(root,P,Q);
    
}