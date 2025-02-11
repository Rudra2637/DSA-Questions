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
void inOrderTraversal(node* root){
    if(root == NULL) return ;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
void preOrderTraversal(node* root){
    if(root == NULL)return ;

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(node* root){
    if(root == NULL)return ;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";

}

int main(){

    node* root = NULL;
    cout<<"Building your tree"<<endl;
    root = buildTree(root);
    cout<<"Traversal Print "<<endl;
    postOrderTraversal(root);

}