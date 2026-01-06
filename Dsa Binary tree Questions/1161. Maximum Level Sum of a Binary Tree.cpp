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
    int maxLevelSum(TreeNode* root) {
        int maxi = INT_MIN;
        int sum = 0;
        int lel = 0;
        int cnt = 1;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            if(temp == NULL){
                if(maxi < sum){
                    maxi = sum;
                    lel  = cnt;
                }
                if(!q.empty()){
                    q.push(NULL);
                    cnt++;
                }
                sum = 0;
            }
            else {
                sum += temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return lel;
    }
};