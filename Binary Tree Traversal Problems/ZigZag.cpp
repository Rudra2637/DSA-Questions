//https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
      int data;
      Node* left;
      Node* right;
  
      // Constructor to initialize a new node
      Node(int val) {
          data = val;
          left = NULL;
          right = NULL;
      }
};

class Solution{
    public:
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>ans;
    	queue<Node*>q;
    	q.push(root);
    	q.push(NULL);
    	
    	while(!q.empty()){
    	    
    	    Node* temp = q.front();
    	    q.pop();
    	    
    	    if(temp == NULL){
    	        ans.push_back(INT_MAX);
    	        if(!q.empty())q.push(NULL);
    	    }
    	    else{
    	        ans.push_back(temp->data);
    	        if(temp->left)q.push(temp->left);
    	        if(temp->right)q.push(temp->right);
    	    
    	    }
    	}
    	vector<int>arr;
    	bool check = false;
    	for(int i=0;i<ans.size();i++){
    	    if(!check && ans[i] != INT_MAX){
    	        arr.push_back(ans[i]);
    	    }
    	    else{
    	        check = true;
    	        i++;
    	        stack<int>st;
    	        while(check && i<ans.size()){
    	            st.push(ans[i]);
    	            i++;
    	            if(ans[i] == INT_MAX)check= false;
    	        }
    	        while(!st.empty()){
    	            arr.push_back(st.top());
    	            st.pop();
    	        }
    	    }
    	}
    	
    	return arr;
    }
};

//Second solution

// vector<int> result;
//     	if(root == NULL)
//     	    return result;
    	
//     	queue<Node*> q;
//     	q.push(root);
    	
//     	bool leftToRight = true;
    	
//     	while(!q.empty()) {
    	    
//     	    int size = q.size();
//     	    vector<int> ans(size);
    	    
//     	    //Level Process
//     	    for(int i=0; i<size; i++) {
    	        
//     	        Node* frontNode = q.front();
//     	        q.pop();
    	        
//     	        //normal insert or reverse insert 
//     	        int index = leftToRight ? i : size - i - 1;
//     	        ans[index] = frontNode -> data;
    	        
//     	        if(frontNode->left)
//     	            q.push(frontNode -> left);
    	            
//     	        if(frontNode->right)
//     	            q.push(frontNode -> right);
//     	    }
    	    
//     	    //direction change karni h
//     	    leftToRight = !leftToRight;
    	   
//     	  for(auto i: ans) {
//     	      result.push_back(i);
//     	  }  
//     	}
//     	    return result;