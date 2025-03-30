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
vector <int> bottomView(Node *root) {
    // Your Code Here
    vector<int>ans;
    
    if(root == NULL)return ans;
    
    map<int,int>m;
    queue<pair<Node*,int> >q;
    
    q.push({root,0});
    
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        
        int hd = temp.second;
        Node* frontNode = temp.first;
        
        m[hd] = frontNode->data;
        
        if(frontNode->left)q.push({frontNode->left,hd-1});
        if(frontNode->right)q.push({frontNode->right,hd+1});
        
    }
    for(auto it:m)ans.push_back(it.second);
    
    return ans;
    
}