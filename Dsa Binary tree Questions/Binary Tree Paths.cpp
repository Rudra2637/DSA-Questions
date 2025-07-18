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

    void solve(TreeNode* root,vector<string>&ans,string temp){
        if(root == NULL)return ;

        if(!root->left && !root->right){
            temp += to_string(root->val);
            ans.push_back(temp);
            
            return ;
        }
        else {
            temp += to_string(root->val);
            string a = "->";
            temp += a; 
        }

        solve(root->left,ans,temp); 
        solve(root->right,ans,temp);

        temp.pop_back();

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp;
        solve(root,ans,temp);
        return ans;
    }
};
