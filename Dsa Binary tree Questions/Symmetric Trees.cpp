#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
  
    // void solve(Node* root,vector<int>&arr){
    //     if(root == NULL){
    //         arr.push_back(-1);
    //         return ;
    //     }
        
    //     solve(root->left,arr);
    //     arr.push_back(root->data);
    //     solve(root->right,arr);
    // }
    
    // void solveRf(Node* root,vector<int>&arr){
    //     if(root == NULL){
    //         arr.push_back(-1);
    //         return ;
    //     }
        
    //     solve(root->right,arr);
    //     arr.push_back(root->data);
    //     solve(root->left,arr);
    // }
//updated
    void solve(Node* root,Node* rootRight,bool &check){
        
        if(root == NULL && rootRight != NULL){
            check = false;
            return ;
        }
        if(root != NULL && rootRight == NULL){
            check = false;
            return ;
        }
        
        if(root == NULL ||rootRight == NULL)return ;
        
        if(root->data != rootRight->data)check = false;
        
        solve(root->left,rootRight->right,check);
        solve(root->right,rootRight->left,check);
        
    }
  
    bool isSymmetric(Node* root) {
        // Code here
        // vector<int>lf;
        // vector<int>rf;
        bool check = true ;
        solve(root->left,root->right,check);
        
        // solveRf(root->right,rf);
        
        // for(int i=0;i<lf.size();i++){
        //     if(lf[i] != rf[i])return false;
        // }
        
        // for(auto it:lf)cout<<it<<" ";
        // cout<<endl;
        
        // for(auto it:rf)cout<<it<<" ";
        
        return check;
        
    }
};
