#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> st;
    vector<int> temp(n);
    st.push(-1);
    for (int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top() >=arr[i]){
            st.pop();
        }
        temp[i] = st.top();
        st.push(arr[i]);
    }

    return temp;
}
