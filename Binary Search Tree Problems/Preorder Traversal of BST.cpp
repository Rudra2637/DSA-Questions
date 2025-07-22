#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

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

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
BinaryTreeNode<int> *inorderToBst(int s,int e,vector<int> arr){
    if(s>e)return NULL;

    int m = (s+e)/2;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[m]);
    root->left = inorderToBst(s,m-1,arr);
    root->right = inorderToBst(m+1,e,arr);

    return root;

}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[0]);
    // for(int i=1;i<preorder.size();i++){
    //     BinaryTreeNode<int>*temp = root;

    //     while(temp){
    //         if(temp->data > preorder[i]){
    //             if(!temp->left){
    //                 temp->left = new BinaryTreeNode<int>(preorder[i]);
    //                 break;
    //             }
    //             temp = temp->left;
    //         }
    //         else {
    //             if(!temp->right){
    //                 temp->right = new BinaryTreeNode<int>(preorder[i]);
    //                 break;
    //             } 
    //             temp = temp->right;
    //         }
    //     }
    // }
    sort(preorder.begin(),preorder.end());
    
    return inorderToBst(0,preorder.size()-1,preorder);
;

}
