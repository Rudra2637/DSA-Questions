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
        void solve(TreeNode* root,vector<vector<int>>&ans,int targetSum,vector<int>arr,int sum){
            if(root == NULL)return ;
            
            if(root->left == NULL && root->right == NULL){
                sum += root->val;
                
                if(sum == targetSum){
                    
                    arr.push_back(root->val);
                    ans.push_back(arr);
                }
            }
            sum += root->val ;
            arr.push_back(root->val);
            solve(root->left,ans,targetSum,arr,sum);
            solve(root->right,ans,targetSum,arr,sum);
            
           arr.pop_back();
           sum -= root->val;
           
        }
    
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<vector<int>>ans;
            vector<int>temp;
            solve(root,ans,targetSum,temp,0);
            return ans;
        }
};