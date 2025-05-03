#include<bits/stdc++.h>
using namespace std;

int main(){
    //declaration of stack using stl
    stack<int>s;

    //Push operation 
    s.push(2);
    s.push(3);
    //Top element
    cout<<s.top()<<endl;
    //Pop operation
    s.pop();
    //To check size of stack 
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    
}