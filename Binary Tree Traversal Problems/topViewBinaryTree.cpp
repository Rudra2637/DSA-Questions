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

vector<int> topView(Node *root) {
    // code here
    vector<int>ans;
    
    if(root == NULL)return ans;
    
    // map<int,map<int,vector<int> > > m;
    // queue<pair<Node*,pair<int,int> > > q;
    
    // q.push({root,{0,0}});
    
    // while(!q.empty()){
    //     auto temp = q.front();
    //     q.pop();
        
    //     Node* frontNode = temp.first;
    //     int hd = temp.second.first;
    //     int lel = temp.second.second;
        
    //     m[hd][lel].push_back(frontNode->data);
        
    //     if(frontNode->left)q.push({frontNode->left,{hd-1,lel+1}});
    //     if(frontNode->right)q.push({frontNode->right,{hd+1,lel+1}});
        
    // }
    
    // for(auto i:m){
    //     for(auto j:i.second){
    //         for(auto k:j.second){
    //             ans.push_back(k);
    //             break;
    //         }
    //         break;
    //     }
    // }
    
    map<int,int>m;
    queue<pair<Node*,int>>q;
    
    q.push({root,0});
    int hd = 0;
    
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        
        
        
        int hd = temp.second;
        Node* frontNode = temp.first;
        
        if(!m.count(hd)) m[hd] = frontNode->data;
        
        if(frontNode->left)q.push({frontNode->left,hd-1});
        
        if(frontNode->right)q.push({frontNode->right,hd+1});
    }
    
    for(auto it:m)ans.push_back(it.second);
    
    
    return ans;
    
}