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

    void solve(TreeNode* root,string temp,int &sum){
        if(root == NULL) return ;
        
        if(!root->left && !root->right){
            temp += to_string(root->val);
            sum += stoi(temp);
            return ;
        }
        else temp += to_string(root->val);

        solve(root->left,temp,sum);
        solve(root->right,temp,sum);

        temp.pop_back();


    }

    int sumNumbers(TreeNode* root) {
        string temp;
        int sum = 0;
        solve(root,temp,sum);

        return sum;
    }
};
