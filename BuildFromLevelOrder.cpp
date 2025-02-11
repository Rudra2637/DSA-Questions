#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;

    node(int d){
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};
node* buildTree(node* root){

    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1)return NULL;

    cout<<"Enter the data for the left side of "<<data<<endl;
    root->left = buildTree(root);
    cout<<"Enter the data for the right side of "<<data<<endl;
    root->right = buildTree(root);
    return root;

}

void buildFromLevel(node* &root){
    queue<node*>q;
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        cout<<"Enter the data for left of "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        
        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter the data for right of "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        
        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(node* root){
    queue<node*>q;
    stack<node*>st;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        st.push(temp);
        // cout<<temp->data<<" ";
        q.pop();

        if(temp->left) q.push(temp->left);
        
        if(temp->right) q.push(temp->right);
    }
    
    //Reversal order Traversal
    while(!st.empty()){
        node* temp = st.top();
        cout<<temp->data<<" ";
        st.pop();
    }
}

int main(){

    node* root = NULL;
    cout<<"Building your tree"<<endl;
    buildFromLevel(root);
    cout<<"Traversal Print "<<endl;
    levelOrderTraversal(root);
   
}