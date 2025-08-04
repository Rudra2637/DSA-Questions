#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool heapify(vector<int>arr,int s,int i){
        int largest = i;
        int leftChild = i*2;
        int rightChild = i*2 + 1;
        
        if(leftChild < s && arr[leftChild] > arr[largest]){
            largest = leftChild;
        }
        if(rightChild < s && arr[rightChild] > arr[largest]){
            largest = rightChild;
        }
        
        if(largest != i)return false;
        else return true;
    }
  
    bool isHeap(Node* tree) {
        // code here
        vector<int>arr;
        queue<Node*>q;
        
        q.push(tree);
        arr.push_back(1);
        bool check = false;
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            arr.push_back(temp->data);
            
            if(!check){
                if(!temp->left && !temp->right) check = true;
                else if(!temp->left && temp->right){
                    return false;
                }
                
                else if(temp->left){
                    q.push(temp->left);
                    
                    if(temp->right)q.push(temp->right);
                    else check = true;
                }
            }
            else  if(temp->left || temp->right) return false;
                
        
            
        }
        int s = arr.size();
        bool checkHeap;
        
        for(int i=s/2;i>0;i--){
            checkHeap = heapify(arr,s,i);
            if(checkHeap == false)return false;
        } 
        
        return true;
    }
    //10 8 7 3 4 2 N
    //100 30 40 10 20 50 N
    //10 5 8 2 N 1 N
};
