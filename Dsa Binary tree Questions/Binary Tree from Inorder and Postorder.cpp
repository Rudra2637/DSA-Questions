#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
    };
    
    Node* newNode(int val) {
        return new Node(val);
    }

    Node* solve(vector<int> inorder, vector<int> postorder,int start,int end,int &idx){
        if(start >  end)return NULL ;
        
        int ele = postorder[idx];
       
        int i = start ;
        for(;i<=end;i++){
            if(inorder[i] == ele)break;
        }
        
        idx--;
        Node* temp = new Node(ele);
        
        temp->right = solve(inorder,postorder,i+1,end,idx);
        temp->left = solve(inorder,postorder,start,i-1,idx);
        
        
        return temp;
    }
    
    
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        // code here
        int idx = inorder.size()-1;
        return solve(inorder,postorder,0,inorder.size()-1,idx);
    }