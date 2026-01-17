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
    const long long MOD = 1000000007; 

    int dfs(TreeNode* root, int totalSum, long long &maxi) {
        if (root == NULL) return 0;

        int left = dfs(root->left, totalSum, maxi);
        int right = dfs(root->right, totalSum, maxi);

        int currSum = left + right + root->val;
        maxi = std::max(maxi, (long long)currSum * (totalSum - currSum));
        
        return currSum;
    }

    int sum_of_tree(TreeNode* root){
        if(root == NULL)return 0;

        int left = sum_of_tree(root->left);
        int right = sum_of_tree(root->right);

        return left + right + root->val;
    }

    int maxProduct(TreeNode* root) {
        int sum = sum_of_tree(root);
        long long maxi = INT_MIN;
        dfs(root,sum,maxi);
        return maxi%MOD;
    }
};