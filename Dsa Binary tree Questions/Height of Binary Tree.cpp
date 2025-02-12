// https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to find the height of a binary tree.
    int levelOrder(Node* root,int s){
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            Node* temp = q.front();
           
            q.pop();
            
            if(temp == NULL){
                s++;
                if(!q.empty())q.push(NULL);
            }
            else{
                if(temp->left)q.push(temp->left);
                
                if(temp->right)q.push(temp->right);
            }
            
        }
        return s;
    }
    int height(Node* node) {
        // code here
        int size = -1;
        int temp = 0;
        int check = node->data;
        if(node->left == NULL && node->right == NULL) return temp;
        return levelOrder(node,size);
     }
};