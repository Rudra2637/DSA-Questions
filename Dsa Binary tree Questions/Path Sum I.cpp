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
        void solve(TreeNode* root,int targetSum,bool &check,int sum){
            if(root == NULL)return ;
    
            if(root->left == NULL && root->right == NULL){
                sum += root->val;
                if(sum == targetSum)check = true;
            }
            sum += root->val;
    
            solve(root->left,targetSum,check,sum);
            solve(root->right,targetSum,check,sum);
        }
    
        bool hasPathSum(TreeNode* root, int targetSum) {
        
            bool check = false;
            solve(root,targetSum,check,0);
            return check;
        }
    };