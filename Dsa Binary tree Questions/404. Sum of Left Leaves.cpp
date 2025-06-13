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
    void solve(TreeNode* root,int &sum){
        if(root == NULL)return ;

        solve(root->left,sum);
        
        solve(root->right,sum);
        
        if(root->left && root->left->left == NULL && root->left->right == NULL)sum += root->left->val;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        
        if(root == NULL)return 0;
        int sum = 0;
        solve(root,sum);
        return sum;
    }
};
