#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* top;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void push(int data,node*  &head){
    node* temp=new node(data);
    temp->next=head;
    head=temp;
}
void pop(node* &head){
    if(head->next==NULL){
        cout<<"stack underflow"<<endl;
    }
    else{
        node* temp=head;
        head=temp->next;
        temp->next=NULL;
    }
}

bool checkempty(node* &head){
    if(head->next==NULL){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
}
void print(node* &head){
    cout<<head->data<<endl;
}
int main(){
    node* obj=new node(4);
    node* head=obj;
    print(head);
    push(5,head);
    print(head);
    push(6,head);
    push(7,head);
    push(8,head);
    print(head);
    pop(head);
    print(head);
    pop(head);
    print(head);
    pop(head);
    pop(head);
    print(head);
    pop(head);
    push(3,head);
    cout<<checkempty(head);
    

}