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

vector<int> rightView(Node *root){
       // Your Code here
    vector<int>ans;
    if(root == NULL)return ans;
       
    map<int,int>m;
    queue<pair<Node*,int>>q;
    q.push({root,0});
       
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
            
        Node* frontNode = temp.first;
        int lel = temp.second;
        m[lel] = frontNode->data;
            
        if(frontNode->left)q.push({frontNode->left,lel+1});
        if(frontNode->right)q.push({frontNode->right,lel+1});
            
    }
    for(auto it:m)ans.push_back(it.second);
    return ans;
       
}