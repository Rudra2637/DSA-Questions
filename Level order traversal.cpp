// https://www.geeksforgeeks.org/problems/level-order-traversal/1
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>>ans;
        vector<int>arr;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        
        
        while(!q.empty()){
            Node* temp = q.front();
            
            q.pop();
            
            if(temp == NULL){
                ans.push_back(arr);
                arr.clear();
                if(!q.empty())q.push(NULL);
            }
            else{
                arr.push_back(temp->data);
            
                if(temp->left)q.push(temp->left);
            
                if(temp->right)q.push(temp->right);
            } 
            
            
        }
        return ans;
    }
};