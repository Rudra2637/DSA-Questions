#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //Recursive Approach

    int totalCnt(TreeNode* root){
        if(root == NULL)return 0;

        int ans = 1 + totalCnt(root->left) + totalCnt(root->right);

        return ans;
    }
    bool checkCBT(TreeNode* root,int i,int cnt){
        if(root == NULL)return true;

        if(i >= cnt)return false;

        else {
            bool left = checkCBT(root->left,(i*2)+1,cnt);
            bool right = checkCBT(root->right,(i*2)+2,cnt);

            return left && right;
        }

       
    }
    //Iterative Approach
    bool isCompleteTree(TreeNode* root) {
        // queue<TreeNode*>q;
        // bool check = false;
        // q.push(root);

        // while(!q.empty()){
        //     TreeNode* temp = q.front();
        //     q.pop();

        //     if(!check){
        //         if(!temp->left && !temp->right)check = true;
        //         else if(!temp->left && temp->right)return false;

        //         else{
        //             if(temp->left){
        //                 q.push(temp->left);
        //                 if(temp->right){
        //                     q.push(temp->right);
        //                 }
        //                 else check = true;
        //             }
        //         }
        //     }
        //     else{
        //         if(temp->left || temp->right)return false;
        //     }
        // }
        int cnt = totalCnt(root);
        return checkCBT(root,0,cnt);
    }
};
