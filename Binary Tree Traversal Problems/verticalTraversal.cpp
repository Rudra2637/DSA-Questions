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

vector<vector<int>> verticalOrder(Node *root) {
    // Your code here
    vector<vector<int>>ans;
    if(root == NULL)return ans;
    
    map<int,map<int,vector<int> > >m;
    queue<pair<Node*,pair<int,int> > >q;
    
    q.push({root,{0,0}});
   
    
    while(!q.empty()){
        auto  temp = q.front();
        q.pop();
        
        int hd = temp.second.first;
        int lel = temp.second.second;
        Node* frontNode = temp.first;
        
        m[hd][lel].push_back(frontNode->data);
        
        if(frontNode->left)q.push({frontNode->left,{hd-1,lel+1}});
        if(frontNode->right)q.push({frontNode->right,{hd+1,lel+1}});
        
    }
    
   
    for(auto i:m){
        vector<int>col;
        for(auto j:i.second){
            for(auto k:j.second){
                col.push_back(k);
            }
           
        }
         ans.push_back(col);
    }
   
    
    
    return ans;
   
}