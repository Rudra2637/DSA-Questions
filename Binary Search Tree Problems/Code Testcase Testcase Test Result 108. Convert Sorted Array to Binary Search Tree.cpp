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
    void solve(vector<int> &nums,TreeNode* &root,int s,int e){

        if(s > e)return ; 
        int m = (s+e)/2;

        root = new TreeNode(nums[m]);
        solve(nums,root->left,s,m-1);
        solve(nums,root->right,m+1,e);

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        TreeNode* root;
        solve(nums,root,0,nums.size()-1);
        return root;
    }
};
