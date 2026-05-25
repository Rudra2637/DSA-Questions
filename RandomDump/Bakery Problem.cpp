#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n,k;
    cin>>n>>k;
    
    int totalCost = n*100;
    int sum = k+(60*n);
    
    if(sum > totalCost){
        cout<<totalCost<<endl;
    }
    else{
        
        cout<<sum<<endl;
    }
}