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

    TreeNode* targetNode(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m,int start){
        queue<TreeNode*>q;
        q.push(root);
        m[root] = nullptr;
        TreeNode* ans = NULL;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front->val == start)ans = front;

            if(front->left){
                q.push(front->left);
                m[front->left] = front;
            }
            if(front->right){
                q.push(front->right);
                m[front->right] = front;
            }
        }
        return ans;
    }
    void infectTree(TreeNode* root,int &ans,unordered_map<TreeNode*,TreeNode*>mp){
        unordered_map<TreeNode*,bool>m;
        queue<TreeNode*>q;
        q.push(root);
        m[root] = true;

        while(!q.empty()){
            bool flag = false;
            int size = q.size();

            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left && !m[front->left]){
                    flag = true;
                    q.push(front->left);
                    m[front->left] = true;
                }
                if(front->right && !m[front->right]){
                    flag = true;
                    q.push(front->right);
                    m[front->right] = true;
                }
                if(mp[front] && !m[mp[front]]){
                    flag = true;
                    q.push(mp[front]);
                    m[mp[front]] = true;
                }
                
            }
            if(flag)ans++;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;

        unordered_map<TreeNode*,TreeNode*>m;
        TreeNode* target = targetNode(root,m,start);
        infectTree(target,ans,m);

        return ans;
    }
};
