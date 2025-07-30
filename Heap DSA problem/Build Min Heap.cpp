#include <bits/stdc++.h> 
using namespace std;

void heapify(vector<int>&arr,int size,int i){
    int leftChild = i*2 + 1;
    int rightChild = i*2 + 2;
    int largest = i;

    if(leftChild < size && arr[largest] > arr[leftChild]) largest = leftChild;
    
    if(rightChild < size && arr[largest] > arr[rightChild]) largest = rightChild;
    

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,size,largest);
    }
    else return ;
}

vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    
    int s = arr.size();
    for(int i=s/2;i>=0;i--) heapify(arr,s,i);
    
    return arr;
}