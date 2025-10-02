#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};


class Solution {
  public:
  
    Node* mergeTwoSortedList(Node* head,Node* root){
        if(!head)return root;
        
        if(!root)return head;
        
        Node* result;
        if(root->data < head->data){
            result = root;
            result->bottom = mergeTwoSortedList(head,result->bottom);
        }
        else {
            result = head;
            result->bottom = mergeTwoSortedList(result->bottom,root);
        }
        
        return result;
    }

    
    Node *flatten(Node *root) {
        // code here
        if(root == NULL)return root;
        Node* head = flatten(root->next);
        
        
        return mergeTwoSortedList(head,root);
        
    }
};

// if(root == NULL)return root;
        
        // Node* temp = root;
        // while(temp->bottom){
        //     if(temp->bottom->data < temp->next->data){
        //         temp = temp->bottom;
        //     }
        //     else{
        //         Node* down = temp->bottom;
        //         temp->bottom = flatten(temp->next);
        //         temp->bottom->bottom = down;
        //         temp = temp->bottom;
        //     }
        // }
        
        // return root;