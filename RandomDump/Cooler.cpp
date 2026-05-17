#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int totalTime = 0;
        
        while(n != m){
            totalTime += n;
            n--;
        }
        cout<<totalTime<<endl;
    }
}
