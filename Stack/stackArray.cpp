#include<iostream>
using namespace std;
class stack{
   public:
   int *arr;
   int top;
   int size;
   stack(int size){
      this->size=size;
      arr=new int[size];
      top=-1;
   }
   void push(int element){
      if(size - top > 1){
         top++;
         arr[top]=element;
      }
      else{
         cout<<"stack overflow"<<endl;
      }
   }
   void pop(){
      if(top==-1){
         cout<<"stack underflow"<<endl;
      }
      else{
         top--;
      }
   }
   void checkempty(){
      if(top==-1){
         cout<<"stack is empty"<<endl;
      }
      else{
         cout<<"stack is not empty"<<endl;
      }
      
   }
   void print(){
 
      cout<<arr[top]<<endl;
      
   }
};
int main(){
  stack s(5);
  s.push(5);
  s.checkempty();
  s.push(6);
  s.push(7);
  s.push(8);
  s.push(10);
  s.print();
  s.push(11);
  s.print();
 



}