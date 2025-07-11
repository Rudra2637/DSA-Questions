#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void flatten(Node *root) {
        // code here
        Node* curr = root;
        
        while(curr != NULL){
            
            if(curr->left){
                Node* temp = curr->left;
                while(temp->right != NULL){
                    temp = temp->right;
                }
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
                
    }
};
