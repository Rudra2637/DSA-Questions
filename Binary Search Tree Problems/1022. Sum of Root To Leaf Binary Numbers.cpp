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

    void getSum(TreeNode* root,string temp,int &sum){
        if(root == NULL){
            return ;
        }
        temp += '0' + root->val;
        getSum(root->left,temp,sum);
        getSum(root->right,temp,sum);
        if(!root->left && !root->right) sum += stoi(temp,nullptr,2);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        getSum(root,"",sum);
        return sum;
    }
};