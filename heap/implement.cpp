#include <bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size = 0;
    
    void insert(int val){
        size++;
        arr[size] = val;
        int i = size;
        
        while(i > 1){
            int parent = i/2;
            
            if(arr[parent] < arr[i]){
                swap(arr[parent],arr[i]);
            }
            i = i/2;
        }
          
    }
    
    void deletion(){
        arr[1] = arr[size];
        size--;
        
        int i=1;
        
        while(i <= size){
            
            int leftChild = i*2;
            int rightChild = i*2 + 1;
            
            if(leftChild < size && arr[i] < arr[leftChild] && arr[rightChild] <  arr[leftChild]){
                swap(arr[leftChild],arr[i]);
                i = leftChild;
            }
            else if(rightChild < size && arr[i] < arr[rightChild] && arr[leftChild] <  arr[rightChild]){
                swap(arr[rightChild],arr[i]);
                i = rightChild;
            }
            else return ;
        }
    }
    void print(){
        for(int i=1;i<=size;i++)cout<<arr[i]<<" ";
        cout<<endl;
    }
};

void heapify(int arr[],int size,int i){
    
    
    int leftChild = i*2;
    int rightChild = i*2+1;
    int largest = i;
    
    if(leftChild < size && arr[leftChild] > arr[largest]){
        largest = leftChild;
    }
    if(rightChild < size && arr[rightChild] > arr[largest]){
        largest = rightChild;
    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
    else return ;
}

int main() {
    // Write C++ code here
    heap h;
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(10);
    h.print();
    h.insert(45);
    h.print();
    h.deletion();
    h.print();
    
    int arr[7] = {-1,40,30,50,60,20,10};
    int n = 7;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    
    cout<<"Printing the array "<<endl;
    
    for(int i = 0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
    

    return 0;
}