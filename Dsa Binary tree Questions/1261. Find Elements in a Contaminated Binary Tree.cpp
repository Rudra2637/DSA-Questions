#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
    public:
        unordered_map<int, int> m;
        
        FindElements(TreeNode* root) {
            if (root != nullptr) {
                tree(root, 0);
            }
        }
        
        bool find(int target) {
            return m.count(target) > 0;
        }
        
        void tree(TreeNode* root, int val) {
            root->val = val;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                TreeNode* temp = q.front();
                q.pop();
                int num = temp->val;
                m[num]++;
                if (temp->left) {
                    temp->left->val = 2 * num + 1;
                    q.push(temp->left);
                }
                if (temp->right) {
                    temp->right->val = 2 * num + 2;
                    q.push(temp->right);
                }
            }
        }
};