#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void insertIntoBST(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
        return;
    }

    Node* curr = new Node(data);
    Node* temp = root;

    while(temp != NULL){
        if(curr->data < temp->data){
            if(temp->left == NULL){
                temp->left = curr;
                return;
            }
            temp = temp->left;
        }
        else{
            if(temp->right == NULL){
                temp->right = curr;
                return;
            }
            temp = temp->right;
        }
    }
}


Node* deleteFromBST(Node* root,int x){
    if(root == NULL)return NULL;

    if(root->data == x){
        //Case 1 : Node with no child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else if(root->data > x){
        root->left = deleteFromBST(root->left, x);
        return root;
    }
    else {
        root->right = deleteFromBST(root->right, x);
        return root;
    }
}
Node* minVal(Node* root){
    if(root == NULL)return NULL;

    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
Node* maxVal(Node* root){
    if(root == NULL)return NULL;

    while(root->right != NULL){
        root = root->right;
    }
    return root;
}
//Recursive version of insertIntoBST
// Node* insertIntoBST(Node* &root, int data) {
//     if (root == NULL)  return new Node(data);
    
    
//     if (data < root->data)  root->left = insertIntoBST(root->left, data);

//     else root->right = insertIntoBST(root->right, data);
    
    
//     return root;
// }

void takeInput(Node* &root) {
    int data;
    cin >> data;
    while(data != -1){
        insertIntoBST(root, data);
        cin >> data;
    }
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = NULL;
    cout << "Enter data to insert into BST (-1 to stop): ";
    takeInput(root);

    cout << "Inorder traversal: ";
    inorder(root);
}
