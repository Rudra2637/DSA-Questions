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

    void solve(TreeNode* lf,TreeNode* rf,bool &check){
        if(!lf && rf){
            check = false;
            return ;
        }
        else if(lf && !rf){
            check = false;
            return ;
        }
        else if(!lf && !rf)return ; 

        if(lf->val != rf->val){
            check = false;
            return ;
        }

        solve(lf->left,rf->right,check);
        solve(lf->right,rf->left,check);
        

    }

    bool isSymmetric(TreeNode* root) {
        bool check = true;
        solve(root->left,root->right,check);

        return check;

    }
};
